/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:37:04 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:10 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// printf("%d\n", ft_isdigit('1'));
// printf("%d\n", isdigit('1'));
// printf("%d\n", ft_isdigit('$'));
// printf("%d\n", isdigit('$'));
// return 0;
// }
