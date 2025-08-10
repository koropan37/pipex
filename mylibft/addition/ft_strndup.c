/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:07:23 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:03:35 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
		str[i] = s[i];
	return (str);
}
