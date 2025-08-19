/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:47:59 by skimura           #+#    #+#             */
/*   Updated: 2025/08/14 21:03:36 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	dup2_and_safe_close(t_pipex *pipex, int *oldfd, int newfd);

void	child_process(t_pipex *pipex, int pipe_idx)
{
	if (pipe_idx == 0)
	{
		dup2_and_safe_close(pipex, &pipex->file->in_fd, STDIN_FILENO);
		dup2_and_safe_close(pipex, &pipex->pipe_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2_and_safe_close(pipex, &pipex->pipe_fd[0], STDIN_FILENO);
		dup2_and_safe_close(pipex, &pipex->file->out_fd, STDOUT_FILENO);
	}
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
