/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:39:40 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:30:47 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <strings.h>

// int	main(void)
// {
// 	char	str1[11] = "0123456789";
// 	char	str2[11] = "0123456789";

// 	bzero(str1 + 3, 4);
// 	ft_bzero(str2 + 3, 4);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }
