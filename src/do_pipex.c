/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 01:31:42 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 20:56:37 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	pipe_and_fork(t_pipex *pipex);
static void	open_fd(t_pipex *pipex);
int			parent_process(t_pipex *pipex);

int	do_pipex(t_pipex *pipex)
{
	open_fd(pipex);
	pipe_and_fork(pipex);
	return (parent_process(pipex));
}

static void	open_fd(t_pipex *pipex)
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

static void	pipe_and_fork(t_pipex *pipex)
{
	int	pid_idx;

	if (pipe(pipex->pipe_fd) < 0)
		clean_up(pipex, "pipe");
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
