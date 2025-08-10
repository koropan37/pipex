/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:25:32 by skimura           #+#    #+#             */
/*   Updated: 2025/07/28 21:41:48 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_dprintf_put_c(int fd, const char c)
{
	ssize_t	bytes;

	bytes = write(fd, &c, 1);
	if (bytes == -1)
		return (-1);
	return ((int)bytes);
}

int	ft_dprintf_put_s(int fd, const char *s)
{
	ssize_t	bytes;

	if (!s)
		bytes = write(fd, "(null)", 6);
	else
		bytes = write(fd, s, ft_strlen(s));
	if (bytes == -1)
		return (-1);
	return ((int)bytes);
}
