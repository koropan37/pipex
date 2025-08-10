/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:55:34 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:36 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (end > start && check_set(s1[end - 1], set))
		end--;
	len = end - start;
	newstr = ft_substr(s1, start, len);
	return (newstr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "12345world trigger6789";
// 	char	set[] = "123456789";
// 	char	*str;

// 	str = ft_strtrim(s1, set);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
