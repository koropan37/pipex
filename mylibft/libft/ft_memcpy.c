/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:40:03 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:06:58 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if ((!dest || !src) && n != 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// unsigned const char str[] = "1234567890";
// unsigned char d[20], d2[20];

// ft_memcpy(d, str, 11);
// memcpy(d2, str ,11);
// printf("%s\n", d);
// printf("%s\n", d2);
// ft_memcpy(d + 2, d, 11);
// memcpy(d2 +2, d2, 11);
// printf("%s\n", d);
// printf("%s\n", d2);

// return (0);
// }
