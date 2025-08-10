/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:10:05 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:07 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// printf("%d\n", ft_isascii('a'));
// printf("%d\n", isascii('a'));
// printf("%d\n", ft_isascii(-1));
// printf("%d\n", isascii(-1));
// return 0;
// }
