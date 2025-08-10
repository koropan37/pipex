/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:44:53 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:30:32 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == (char)c)
			return ((char *)&s[n]);
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// const char str[] = "apple";

// printf("%s\n",ft_strrchr(str, 112));
// printf("%s\n",strrchr(str, 112));
// return (0);
// }
