/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:41:36 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:03:37 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned int	ft_lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return (a / ft_gcd(a, b) * b);
}
