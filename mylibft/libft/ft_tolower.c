/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:44:14 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:23 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// printf("%d\n", ft_tolower('A'));
// printf("%d\n", tolower('A'));
// 	return 0;
// }
