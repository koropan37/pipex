/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:47:59 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 21:11:10 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	safe_close(int fd);
void	safe_close_all(t_pipex *pipex);

void	clean_up(t_pipex *pipex, char *error_txt)
{
	ft_dprintf(STDERR_FILENO, "pipex: %s: %s\n", error_txt, strerror(errno));
	safe_close_all(pipex);
	free_pipex_and_err_exit(pipex);
}

void	safe_close(int fd)
{
	if (fd < 0)
		return ;
	if (close(fd) < 0)
		perror("close filed");
}

void	safe_close_all(t_pipex *pipex)
{
	if (!pipex)
		return ;
	safe_close(pipex->file->in_fd);
	pipex->file->in_fd = -1;
	safe_close(pipex->file->out_fd);
	pipex->file->out_fd = -1;
	safe_close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	safe_close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
}
