/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:12 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:18 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	int_len(int n)
{
	int		i_len;
	long	i_nb;

	i_len = 0;
	i_nb = n;
	if (i_nb <= 0)
	{
		i_nb = -i_nb;
		i_len++;
	}
	while (i_nb != 0)
	{
		i_nb /= 10;
		i_len++;
	}
	return (i_len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = int_len(n);
	nb = (long)n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		n = -2147483648;
// 	char	*s = ft_itoa(n);
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }
