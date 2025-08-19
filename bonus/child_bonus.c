/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:36:09 by skimura           #+#    #+#             */
/*   Updated: 2025/08/14 21:01:30 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	dup2_and_safe_close(t_pipex *pipex, int *oldfd, int newfd);
static void	first_cp(t_pipex *pipex);
static void	last_cp(t_pipex *pipex, int pipe_idx);
static void	other_cp(t_pipex *pipex, int pipe_idx);

void	child_process(t_pipex *pipex, int pipe_idx)
{
	if (pipe_idx == 0)
		first_cp(pipex);
	else if (pipe_idx == pipex->cmd->cmd_cnt - 1)
		last_cp(pipex, pipe_idx);
	else
		other_cp(pipex, pipe_idx);
	safe_close_all(pipex);
	if (pipe_idx == 0 && pipex->file->in_err)
		free_pipex_and_err_exit(pipex);
	else if (pipe_idx == pipex->cmd->cmd_cnt - 1 && pipex->file->out_err)
		free_pipex_and_err_exit(pipex);
	execve(find_execution_path(pipex, pipe_idx), pipex->cmd->cmds[pipe_idx],
		pipex->ep);
	if (errno == ENOENT)
		error_cmd(pipex);
	else if (errno == ENOEXEC || errno == EACCES || errno == ETXTBSY)
		error_pd(pipex);
}

static void	dup2_and_safe_close(t_pipex *pipex, int *oldfd, int newfd)
{
	if (*oldfd < 0)
		return ;
	if (dup2(*oldfd, newfd) < 0)
		clean_up(pipex, "dup2");
	safe_close(*oldfd);
	*oldfd = -1;
}

static void	first_cp(t_pipex *pipex)
{
	if (pipex->heredoc)
		dup2_and_safe_close(pipex, &pipex->heredoc->tmp_fd, STDIN_FILENO);
	else
		dup2_and_safe_close(pipex, &pipex->file->in_fd, STDIN_FILENO);
	dup2_and_safe_close(pipex, &pipex->pipes_fd[0][1], STDOUT_FILENO);
}

static void	last_cp(t_pipex *pipex, int pipe_idx)
{
	dup2_and_safe_close(pipex, &pipex->pipes_fd[pipe_idx - 1][0], STDIN_FILENO);
	dup2_and_safe_close(pipex, &pipex->file->out_fd, STDOUT_FILENO);
}

static void	other_cp(t_pipex *pipex, int pipe_idx)
{
	dup2_and_safe_close(pipex, &pipex->pipes_fd[pipe_idx - 1][0], STDIN_FILENO);
	dup2_and_safe_close(pipex, &pipex->pipes_fd[pipe_idx][1], STDOUT_FILENO);
}
