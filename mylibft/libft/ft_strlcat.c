/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:43:03 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:14 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	src_len = ft_strlen(src);
	i = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	while (i < size - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i < size - dst_len)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// char dest[] = "world";
// const char src[] = "trigger";
// size_t n = 20;

// printf("%zu\n", ft_strlcat(dest, src, n));
// return (0);
// }
