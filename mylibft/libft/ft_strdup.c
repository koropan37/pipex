/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:47:24 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:08:57 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s[] = "world";
// 	char	*s2 = ft_strdup(s);
// 	char	*s3 = strdup(s);

// 	printf("%s %s\n", s, s2);
// 	printf("%s %s\n", s, s3);
// 	free(s2);
// 	free(s3);
// 	return (0);
// }
