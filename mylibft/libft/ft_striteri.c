/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:43 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:01 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void change(unsigned int i, char *c)
// 	{
// 		(void)i;
// 		if (*c >= 'a' && *c <= 'z')
// 			*c -= 32;
// 	}
// int main()
// {
// 	char str[] = "hello";
// 	ft_striteri(str, change);

// 	printf("%s\n", str);
// 	return (0);
// }
