/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:46:36 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:09:45 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (!big || !little)
		return (0);
	i = 0;
	l_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i + l_len <= len)
	{
		if (ft_strncmp(&big[i], little, l_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// const char big[] = "abcdef";
// const char little[] = "cde";

// printf("%s\n", ft_strnstr(big, little, 10));
// return (0);
// }
