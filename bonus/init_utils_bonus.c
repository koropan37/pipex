/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 08:30:12 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 17:48:54 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_file(t_pipex *pipex, int ac, char *av[]);
void	init_cmd(t_pipex *pipex, int ac, char *av[]);
void	init_pid(t_pipex *pipex);
void	fill_cmds(t_pipex *pipex, char *av[]);
void	init_pipe_fd(t_pipex *pipex);

void	init_file(t_pipex *pipex, int ac, char *av[])
{
	pipex->file = ft_calloc(1, sizeof(t_file));
	if (!pipex->file)
		init_error(pipex);
	if (pipex->heredoc)
		pipex->file->infile = NULL;
	else
		pipex->file->infile = av[1];
	pipex->file->outfile = av[ac - 1];
	pipex->file->in_fd = -1;
	pipex->file->out_fd = -1;
	pipex->file->in_err = 0;
	pipex->file->out_err = 0;
}

void	init_cmd(t_pipex *pipex, int ac, char *av[])
{
	pipex->cmd = ft_calloc(1, sizeof(t_cmd));
	if (!pipex->cmd)
		init_error(pipex);
	if (pipex->heredoc)
		pipex->cmd->cmd_cnt = ac - 4;
	else
		pipex->cmd->cmd_cnt = ac - 3;
	pipex->cmd->cmds = ft_calloc(pipex->cmd->cmd_cnt + 1, sizeof(char **));
	if (!pipex->cmd->cmds)
		init_error(pipex);
	fill_cmds(pipex, av);
}

void	fill_cmds(t_pipex *pipex, char *av[])
{
	int	i;

	i = 0;
	while (i < pipex->cmd->cmd_cnt)
	{
		if (pipex->heredoc)
			pipex->cmd->cmds[i] = ft_split(av[3 + i], ' ');
		else
			pipex->cmd->cmds[i] = ft_split(av[2 + i], ' ');
		if (!pipex->cmd->cmds[i])
		{
			while (i > 0)
				free_arr(pipex->cmd->cmds[--i]);
			init_error(pipex);
		}
		i++;
	}
	pipex->cmd->cmds[pipex->cmd->cmd_cnt] = NULL;
}

void	init_pid(t_pipex *pipex)
{
	pipex->pids = ft_calloc(pipex->cmd->cmd_cnt, sizeof(pid_t));
	if (!pipex->pids)
		init_error(pipex);
}

void	init_pipe_fd(t_pipex *pipex)
{
	int	i;

	pipex->pipes_fd = ft_calloc(pipex->cmd->cmd_cnt - 1, sizeof(int *));
	if (!pipex->pipes_fd)
		init_error(pipex);
	i = 0;
	while (i < pipex->cmd->cmd_cnt - 1)
	{
		pipex->pipes_fd[i] = ft_calloc(2, sizeof(int));
		if (!pipex->pipes_fd[i])
			init_error(pipex);
		i++;
	}
}
