/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:19:18 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 20:52:56 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void		normal_mode(t_pipex *pipex);
static void	create_pipe(t_pipex *pipex);
static void	fork_and_child_process(t_pipex *pipex);

int	do_pipex(t_pipex *pipex)
{
	if (pipex->heredoc)
		here_doc_mode(pipex);
	else
		normal_mode(pipex);
	create_pipe(pipex);
	fork_and_child_process(pipex);
	return (parent_process(pipex));
}

void	normal_mode(t_pipex *pipex)
{
	pipex->file->in_fd = open(pipex->file->infile, O_RDONLY);
	if (pipex->file->in_fd < 0)
	{
		pipex->file->in_fd = open("/dev/null", O_RDONLY);
		ft_dprintf(STDERR_FILENO, "pipex: %s: %s\n", pipex->file->infile,
			strerror(errno));
		pipex->file->in_err = 1;
	}
	pipex->file->out_fd = open(pipex->file->outfile,
			O_CREAT | O_WRONLY | O_TRUNC, OUTFILE_PERMS);
	if (pipex->file->out_fd < 0)
	{
		ft_dprintf(STDERR_FILENO, "pipex: %s: %s\n", pipex->file->outfile,
			strerror(errno));
		pipex->file->out_err = 1;
	}
	if (pipex->file->in_err && pipex->file->out_err)
		free_pipex_and_err_exit(pipex);
}

static void	create_pipe(t_pipex *pipex)
{
	int	pipe_idx;

	pipe_idx = 0;
	while (pipe_idx < pipex->cmd->cmd_cnt - 1)
	{
		if (pipe(pipex->pipes_fd[pipe_idx]) < 0)
			clean_up(pipex, "pipe");
		pipe_idx++;
	}
}

static void	fork_and_child_process(t_pipex *pipex)
{
	int	pid_idx;

	pid_idx = 0;
	while (pid_idx < pipex->cmd->cmd_cnt)
	{
		pipex->pids[pid_idx] = fork();
		if (pipex->pids[pid_idx] < 0)
			clean_up(pipex, "fork");
		if (pipex->pids[pid_idx] == 0)
			child_process(pipex, pid_idx);
		pid_idx++;
	}
}
