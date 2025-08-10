/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:00:00 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:32:00 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_dprintf_put_u_hex(int fd, unsigned long long n, char spec);
int	ft_dprintf_put_p(int fd, void *p);
int	ft_dprintf_put_d_i(int fd, long long n);

int	ft_dprintf_unsigned_nbr_base(int fd, unsigned long long n, int base,
		const char *digits)
{
	char	bit[65];
	size_t	i;
	size_t	count;
	ssize_t	bytes;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	while (n)
	{
		bit[i++] = digits[n % base];
		n /= base;
	}
	while (i > 0)
	{
		bytes = write(fd, &bit[--i], 1);
		if (bytes == -1)
			return (-1);
		count += bytes;
	}
	return ((int)count);
}

int	ft_dprintf_put_p(int fd, void *p)
{
	uintptr_t	pointer;
	ssize_t		bytes;
	size_t		count;

	if (!p)
		return (write(fd, "(nil)", 5));
	pointer = (uintptr_t)p;
	bytes = write(fd, "0x", 2);
	if (bytes == -1)
		return (-1);
	count = bytes;
	if (pointer == 0)
	{
		bytes = write(fd, "0", 1);
		if (bytes == -1)
			return (-1);
		return ((int)count + (int)bytes);
	}
	bytes = ft_dprintf_unsigned_nbr_base(fd, pointer, 16, DIGITS_16);
	if (bytes == -1)
		return (-1);
	return ((int)count + (int)bytes);
}

int	ft_dprintf_put_d_i(int fd, long long n)
{
	ssize_t				bytes;
	size_t				count;
	unsigned long long	number;

	count = 0;
	if (n < 0)
	{
		bytes = write(fd, "-", 1);
		if (bytes == -1)
			return (-1);
		count += bytes;
		number = (unsigned long long)(-(n + 1)) + 1;
	}
	else
		number = (unsigned long long)n;
	bytes = ft_dprintf_unsigned_nbr_base(fd, number, 10, DIGITS_10);
	if (bytes == -1)
		return (-1);
	count += bytes;
	return ((int)count);
}

int	ft_dprintf_put_u_hex(int fd, unsigned long long n, char spec)
{
	size_t	count;

	count = 0;
	if (spec == 'u')
		count += ft_dprintf_unsigned_nbr_base(fd, n, 10, DIGITS_10);
	if (spec == 'x')
		count += ft_dprintf_unsigned_nbr_base(fd, n, 16, DIGITS_16);
	if (spec == 'X')
		count += ft_dprintf_unsigned_nbr_base(fd, n, 16, DIGITS_16X);
	return ((int)count);
}
