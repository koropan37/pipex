/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:37:36 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:00 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// printf("%d\n", ft_isalnum('a'));
// printf("%d\n", isalnum('a'));
// printf("%d\n", ft_isalnum('$'));
// printf("%d\n", isalnum('$'));
// return 0;
// }
