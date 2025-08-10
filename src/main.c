/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:54:06 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 20:37:31 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char *av[], char *ep[])
{
	t_pipex	*pipex;
	int		ret;

	parse_line(ac, av);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
	{
		print_alloc_error();
		exit(EXIT_FAILURE);
	}
	init_pipex(pipex, ac, av, ep);
	ret = do_pipex(pipex);
	free_pipex(pipex);
	return (ret);
}
