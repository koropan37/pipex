/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:42:20 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:07:03 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((!dest || !src) && n != 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n-- > 0)
		d[n] = s[n];
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// unsigned const char str[] = "1234567890";
// unsigned char d[20], d2[20];
// size_t n = 15;

// ft_memmove(d, str, n);
// memmove(d2, str ,n);
// printf("%s\n", d);
// printf("%s\n", d2);
// ft_memmove(d + 2, d, n);
// memmove(d2 +2, d2, n);
// printf("%s\n", d);
// printf("%s\n", d2);
// return (0);
// }
