/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:46:12 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:06:51 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*d1;
	unsigned const char	*d2;
	size_t				i;

	if (!s1 || !s2)
		return (0);
	d1 = (unsigned const char *)s1;
	d2 = (unsigned const char *)s2;
	i = 0;
	while (i < n && (d1[i] == d2[i]))
		i++;
	return (d1[i] - d2[i]);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// const char s[] = "abcde\0f";
// const char k[] = "abcde\0g";
// size_t n1 = 10;
// size_t n2 = 5;

// printf("%d\n", ft_memcmp(s, k, n1));
// printf("%d\n", memcmp(s, k, n1));
// printf("%d\n", strcmp(s, k));
// printf("%d\n", ft_memcmp(s, k, n2));
// printf("%d\n", memcmp(s, k, n2));
// 	return (0);
// }
