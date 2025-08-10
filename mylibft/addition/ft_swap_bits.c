/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:01:29 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:05:35 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned char	ft_swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
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
// 	unsigned char	x;

// 	x = swap_bits((unsigned char)2);
// 	print_bits(x);
// 	return (0);
// }
