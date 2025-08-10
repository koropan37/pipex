/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:57:47 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:08:41 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd((nbr / 10), fd);
	c = ((nbr % 10)) + '0';
	ft_putchar_fd(c, fd);
}

// int	main()
// {
// int n = -2147483648;
// ft_putnbr_fd(n, 1);
// 	return 0;
// }
