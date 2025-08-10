/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:41:57 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 15:39:14 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printcheck(const char **format, va_list args)
{
	char	spec;
	int		bytes;

	spec = **format;
	(*format)++;
	bytes = 0;
	if (spec == 'c')
		bytes = ft_put_c(va_arg(args, int));
	if (spec == 's')
		bytes = ft_put_s(va_arg(args, char *));
	if (spec == 'p')
		bytes = ft_put_p(va_arg(args, void *));
	if (spec == 'd' || spec == 'i')
		bytes = ft_put_d_i((long long)va_arg(args, int));
	if (spec == 'u' || spec == 'x' || spec == 'X')
		bytes = ft_put_u_hex(va_arg(args, unsigned int), spec);
	if (spec == '%')
		bytes = ft_put_c('%');
	return (bytes);
}

static int	ft_in_printf(const char *format, va_list args)
{
	int	total;
	int	bytes;

	total = 0;
	while (*format)
	{
		if (*format != '%')
		{
			bytes = write(1, format++, 1);
			if (bytes == -1)
				return (-1);
		}
		else
		{
			format++;
			bytes = ft_printcheck(&format, args);
			if (bytes == -1)
				return (-1);
		}
		if (total > INT_MAX - bytes)
			return (-1);
		total += bytes;
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	result = ft_in_printf(format, args);
	va_end(args);
	return (result);
}
