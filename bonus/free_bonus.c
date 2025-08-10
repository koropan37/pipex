/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 08:35:59 by skimura           #+#    #+#             */
/*   Updated: 2025/08/04 15:14:07 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	free_cmd(t_pipex *pipex);

void	*free_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

void	free_pipex_and_err_exit(t_pipex *pipex)
{
	free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	if (!pipex)
		return ;
	if (pipex->heredoc)
		free(pipex->heredoc);
	if (pipex->file)
		free(pipex->file);
	if (pipex->pipes_fd)
	{
		i = 0;
		while (i < pipex->cmd->cmd_cnt - 1)
			free(pipex->pipes_fd[i++]);
		free(pipex->pipes_fd);
	}
	free_cmd(pipex);
	if (pipex->pids)
		free(pipex->pids);
	free(pipex);
}

static void	free_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd && pipex->cmd->cmds)
	{
		i = 0;
		while (i < pipex->cmd->cmd_cnt)
			free_arr(pipex->cmd->cmds[i++]);
		free(pipex->cmd->cmds);
	}
	if (pipex->cmd)
		free(pipex->cmd);
}
