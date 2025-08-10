/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:49:23 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:28 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	sub_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	sub_len = ft_strlen(s);
	if (start >= sub_len)
		return (ft_strdup(""));
	if (len > sub_len - start)
		len = sub_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char const		origin[] = "trigger";
// 	unsigned int	start = 3;
// 	size_t			len = 5;
// 	char			copy = ft_substr(origin, start, len);

// 	printf("%s\n", s);
// 	free(copy);
// 	return (0);
// }
