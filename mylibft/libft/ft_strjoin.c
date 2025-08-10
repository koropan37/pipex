/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:55:06 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:09 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, s1_len);
	ft_memcpy(newstr + s1_len, s2, s2_len);
	newstr[s1_len + s2_len] = '\0';
	return (newstr);
}

// #include <stdio.h>

// int main()
// {
// char const s1[] = "world";
// char const s2[] = "trigger";
// char *s3 = ft_strjoin(s1, s2);

// printf("%s\n", s3);
// free(s3);
// return (0);
// }
