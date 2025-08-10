/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:43:36 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:18 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// printf("%d\n", ft_toupper('a'));
// printf("%d\n", toupper('a'));
// 	return 0;
// }
