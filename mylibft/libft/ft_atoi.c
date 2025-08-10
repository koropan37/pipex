/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:46:49 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:30:43 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	overflow(int sign)
{
	if (sign == 1)
		return (INT_MAX);
	else
		return (INT_MIN);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	if (!nptr)
		return (0);
	sign = 1;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (result > ((long)INT_MAX - (*nptr - '0')) / 10)
			return (overflow(sign));
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(sign * result));
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// const char str[] = "2147483648";
// printf("%d\n", ft_atoi(str));
// printf("%d\n", atoi(str));
// return (0);
// }
