/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:30 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:56 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// char	change(unsigned int i, char c)
// {
// 	(void)i;
// 	if ('a' <= c && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int main(void)
// {
// 	const char s[] = "world";
// 	char *s2 = ft_strmapi(s, change);

// 	if (s2)
// 	{
// 		printf("%s\n", s2);
// 		free(s2);
// 	}
// 	return 0;
// }
