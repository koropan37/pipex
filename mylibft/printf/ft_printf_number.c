/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:37:29 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:00:59 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_unsigned_nbr_base(unsigned long long n, int base, const char *digits)
{
	char	bit[65];
	size_t	i;
	size_t	count;
	ssize_t	bytes;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		bit[i++] = digits[n % base];
		n /= base;
	}
	while (i > 0)
	{
		bytes = write(1, &bit[--i], 1);
		if (bytes == -1)
			return (-1);
		count += bytes;
	}
	return ((int)count);
}

int	ft_put_p(void *p)
{
	uintptr_t	pointer;
	ssize_t		bytes;
	size_t		count;

	if (!p)
		return (write(1, "(nil)", 5));
	pointer = (uintptr_t)p;
	bytes = write(1, "0x", 2);
	if (bytes == -1)
		return (-1);
	count = bytes;
	if (pointer == 0)
	{
		bytes = write(1, "0", 1);
		if (bytes == -1)
			return (-1);
		return ((int)count + (int)bytes);
	}
	bytes = ft_unsigned_nbr_base(pointer, 16, DIGITS_16);
	if (bytes == -1)
		return (-1);
	return ((int)count + (int)bytes);
}

int	ft_put_d_i(long long n)
{
	ssize_t				bytes;
	size_t				count;
	unsigned long long	number;

	count = 0;
	if (n < 0)
	{
		bytes = write(1, "-", 1);
		if (bytes == -1)
			return (-1);
		count += bytes;
		number = (unsigned long long)(-(n + 1)) + 1;
	}
	else
		number = (unsigned long long)n;
	bytes = ft_unsigned_nbr_base(number, 10, DIGITS_10);
	if (bytes == -1)
		return (-1);
	count += bytes;
	return ((int)count);
}

int	ft_put_u_hex(unsigned long long n, char spec)
{
	size_t	count;

	count = 0;
	if (spec == 'u')
		count += ft_unsigned_nbr_base(n, 10, DIGITS_10);
	if (spec == 'x')
		count += ft_unsigned_nbr_base(n, 16, DIGITS_16);
	if (spec == 'X')
		count += ft_unsigned_nbr_base(n, 16, DIGITS_16X);
	return ((int)count);
}
