/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:36:34 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:03 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// printf("%d\n", ft_isalpha('a'));
// printf("%d\n", isalpha('a'));
// printf("%d\n", ft_isalpha('$'));
// printf("%d\n", isalpha('$'));
// return (0);
// }
