/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:39:16 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:07:07 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// unsigned char str1[11] = "abcdefghij";
// unsigned char str2[11] = "abcdefghij";

// ft_memset(str1 + 4, 0, 6);
// printf("%s\n", str1);
// memset(str2 + 4, 0, 6);
// printf("%s\n", str2);
// return (0);
// }
