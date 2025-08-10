/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:03:14 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 21:01:01 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	init_file(t_pipex *pipex, int ac, char *av[]);
static void	init_cmd(t_pipex *pipex, int ac, char *av[]);
static void	init_pid(t_pipex *pipex);
static void	fill_cmds(t_pipex *pipex, char *av[]);

void	init_pipex(t_pipex *pipex, int ac, char *av[], char *ep[])
{
	init_file(pipex, ac, av);
	init_cmd(pipex, ac, av);
	init_pid(pipex);
	pipex->ep = ep;
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
}

static void	init_file(t_pipex *pipex, int ac, char *av[])
{
	pipex->file = ft_calloc(1, sizeof(t_file));
	if (!pipex->file)
		init_error(pipex);
	pipex->file->infile = av[1];
	pipex->file->outfile = av[ac - 1];
	pipex->file->in_fd = -1;
	pipex->file->out_fd = -1;
	pipex->file->in_err = 0;
	pipex->file->out_err = 0;
}

static void	init_cmd(t_pipex *pipex, int ac, char *av[])
{
	pipex->cmd = ft_calloc(1, sizeof(t_cmd));
	if (!pipex->cmd)
		init_error(pipex);
	pipex->cmd->cmd_cnt = ac - 3;
	pipex->cmd->cmds = ft_calloc(pipex->cmd->cmd_cnt + 1, sizeof(char **));
	if (!pipex->cmd->cmds)
		init_error(pipex);
	fill_cmds(pipex, av);
}

static void	fill_cmds(t_pipex *pipex, char *av[])
{
	int	i;

	i = 0;
	while (i < pipex->cmd->cmd_cnt)
	{
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

static void	init_pid(t_pipex *pipex)
{
	pipex->pids = ft_calloc(pipex->cmd->cmd_cnt, sizeof(pid_t));
	if (!pipex->pids)
		init_error(pipex);
}
