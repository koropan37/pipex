/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:55:12 by skimura           #+#    #+#             */
/*   Updated: 2025/08/11 15:14:21 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parse_line(int ac, char *av[])
{
	(void)av;
	if (ac != 5)
	{
		ft_dprintf(STDERR_FILENO,
			"Usage:./pipex infile <cmd1> <cmd2> outfile\n");
		exit(EXIT_FAILURE);
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

void	print_alloc_error(void)
{
	ft_dprintf(STDERR_FILENO, "pipex: memory allocation error\n");
}

void	init_error(t_pipex *pipex)
{
	print_alloc_error();
	free_pipex_and_err_exit(pipex);
}
