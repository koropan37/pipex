/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:45:06 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:51 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// const char s[] = "abcdef";
// const char k[] = "abcdeg";
// size_t n1 = 10;
// size_t n2 = 5;

// printf("%d\n", ft_strncmp(s, k, n1));
// printf("%d\n", strncmp(s, k, n1));
// printf("%d\n", ft_strncmp(s, k, n2));
// printf("%d\n", strncmp(s, k, n2));
// 	return (0);
// }
