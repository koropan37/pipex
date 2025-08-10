/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:45:56 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:06:55 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*b;
	size_t				i;

	if (!s)
		return (NULL);
	b = (unsigned const char *)s;
	i = 0;
	while (i < n)
	{
		if (b[i] == (unsigned char)c)
			return ((void *)(b + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// const char data[] = "a\0pple";
// char *str1, *str2;
// str1 = ft_memchr(data, 'p',10);
// printf("%s\n",str1);
// str2 = memchr(data, 'p',10);
// printf("%s\n",str2);
// return (0);
// }
