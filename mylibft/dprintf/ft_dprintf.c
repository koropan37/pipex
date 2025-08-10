/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:00:00 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:32:30 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_in_dprintf(int fd, const char *format, va_list args);
static int	ft_dprintf_printcheck(int fd, const char **format, va_list args);

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		result;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	result = ft_in_dprintf(fd, format, args);
	va_end(args);
	return (result);
}

static int	ft_in_dprintf(int fd, const char *format, va_list args)
{
	int	total;
	int	bytes;

	total = 0;
	while (*format)
	{
		if (*format != '%')
		{
			bytes = write(fd, format++, 1);
			if (bytes == -1)
				return (-1);
		}
		else
		{
			format++;
			bytes = ft_dprintf_printcheck(fd, &format, args);
			if (bytes == -1)
				return (-1);
		}
		if (total > INT_MAX - bytes)
			return (-1);
		total += bytes;
	}
	return (total);
}

static int	ft_dprintf_printcheck(int fd, const char **format, va_list args)
{
	char	spec;
	int		bytes;

	spec = **format;
	(*format)++;
	bytes = 0;
	if (spec == 'c')
		bytes = ft_dprintf_put_c(fd, va_arg(args, int));
	if (spec == 's')
		bytes = ft_dprintf_put_s(fd, va_arg(args, char *));
	if (spec == 'p')
		bytes = ft_dprintf_put_p(fd, va_arg(args, void *));
	if (spec == 'd' || spec == 'i')
		bytes = ft_dprintf_put_d_i(fd, (long long)va_arg(args, int));
	if (spec == 'u' || spec == 'x' || spec == 'X')
		bytes = ft_dprintf_put_u_hex(fd, va_arg(args, unsigned int), spec);
	if (spec == '%')
		bytes = ft_dprintf_put_c(fd, '%');
	return (bytes);
}
