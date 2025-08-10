/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:47:59 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 20:59:19 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


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

void	free_pipex(t_pipex *pipex)
{
	int	i;

	if (!pipex)
		return ;
	if (pipex->file)
		free(pipex->file);
	if (pipex->cmd && pipex->cmd->cmds)
	{
		i = 0;
		while (i < pipex->cmd->cmd_cnt)
			free_arr(pipex->cmd->cmds[i++]);
		free(pipex->cmd->cmds);
	}
	if (pipex->cmd)
		free(pipex->cmd);
	if (pipex->pids)
		free(pipex->pids);
	free(pipex);
}

void	free_pipex_and_err_exit(t_pipex *pipex)
{
	free_pipex(pipex);
	exit(EXIT_FAILURE);
}
