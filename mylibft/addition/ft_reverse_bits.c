/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:42:04 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:05:13 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned char	ft_reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	result;

	i = 8;
	result = 0;
	while (i--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}

// #include <unistd.h>

// void	print_bits(unsigned char octet)
// {
// 	int				i;
// 	unsigned char	bit;

// 	i = 8;
// 	while (i--)
// 	{
// 		bit = ((octet >> i) & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// }
// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char	res;

// 	res = reverse_bits((unsigned char)5);
// 	print_bits(res);
// 	return (0);
// }
