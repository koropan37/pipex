/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:54:06 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 17:54:20 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	parse_line(int ac, char *av[])
{
	if (ac < 5)
	{
		ft_dprintf(STDERR_FILENO,
			"Usage: ./pipex infile <cmd1> <cmd2> .. outfile\n");
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(av[1], "here_doc") == 0 && ac < 6)
	{
		ft_dprintf(STDERR_FILENO,
			"Usage: ./pipex  here_doc LIMITER <cmd1> <cmd2> .. file");
		exit(EXIT_FAILURE);
	}
}
