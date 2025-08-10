/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:03:14 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 17:57:08 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_file(t_pipex *pipex, int ac, char *av[]);
void	init_cmd(t_pipex *pipex, int ac, char *av[]);
void	init_pid(t_pipex *pipex);
void	fill_cmds(t_pipex *pipex, char *av[]);
void	init_pipe_fd(t_pipex *pipex);

void	init_pipex(t_pipex *pipex, int ac, char *av[], char *ep[])
{
	if (ft_strcmp(av[1], "here_doc") == 0)
		init_here_doc(pipex, av);
	else
		pipex->heredoc = NULL;
	pipex->ep = ep;
	init_file(pipex, ac, av);
	init_cmd(pipex, ac, av);
	init_pipe_fd(pipex);
	init_pid(pipex);
}

void	print_alloc_error(void)
{
	ft_dprintf(STDERR_FILENO, "pipex: memory allocation error\n");
}

void	init_error(t_pipex *pipex)
{
	print_alloc_error();
	free_pipex_and_err_exit(pipex);
}
