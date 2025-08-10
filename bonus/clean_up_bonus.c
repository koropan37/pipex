/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:47:59 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 18:30:57 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	safe_close(int fd);
void	safe_close_all(t_pipex *pipex);
void	*free_arr(char **arr);
void	error_cmd(t_pipex *pipex);
void	error_pd(t_pipex *pipex);

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
	int	i;

	if (!pipex || !pipex->pipes_fd)
		return ;
	safe_close(pipex->file->in_fd);
	pipex->file->in_fd = -1;
	safe_close(pipex->file->out_fd);
	pipex->file->out_fd = -1;
	i = 0;
	while (i < pipex->cmd->cmd_cnt - 1)
	{
		safe_close(pipex->pipes_fd[i][0]);
		pipex->pipes_fd[i][0] = -1;
		safe_close(pipex->pipes_fd[i][1]);
		pipex->pipes_fd[i][1] = -1;
		i++;
	}
}

void	error_cmd(t_pipex *pipex)
{
	free_pipex(pipex);
	exit(COMMAND_NOT_FOUND);
}

void	error_pd(t_pipex *pipex)
{
	free_pipex(pipex);
	exit(PERMISSION_DENIED);
}
