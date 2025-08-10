/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:06:26 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:03:37 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max_n;

	if (len == 0)
		return (0);
	i = 1;
	max_n = tab[0];
	while (i < len)
	{
		if (tab[i] > max_n)
			max_n = tab[i];
		i++;
	}
	return (max_n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	tab[] = {5, 4, 7, 9, 10};

// 	printf("%d\n", max(tab, 5));
// 	return (0);
// }
