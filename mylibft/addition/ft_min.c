/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:22:27 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:04:56 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_min(int *tab, unsigned int len)
{
	unsigned int	i;
	int				min_n;

	if (len == 0)
		return (0);
	i = 1;
	min_n = tab[0];
	while (i < len)
	{
		if (tab[i] < min_n)
			min_n = tab[i];
		i++;
	}
	return (min_n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	tab[] = {5, 4, 7, 9, 10};

// 	printf("%d\n", min(tab, 5));
// 	return (0);
// }
