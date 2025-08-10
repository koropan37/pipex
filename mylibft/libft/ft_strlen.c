/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:39:19 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:10:01 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// const char str[] = "world trigger";

// printf("%zu\n", ft_strlen(str));
// printf("%zu\n", strlen(str));
// return (0);
// }
