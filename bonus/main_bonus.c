/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:54:06 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 17:54:29 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
