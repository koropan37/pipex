/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:55:11 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:03:34 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	j;
	size_t	i;
	int		f;

	i = 0;
	while (s[i])
	{
		j = 0;
		f = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				f = 1;
			j++;
		}
		if (f == 0)
			return (i);
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	const char	*s = "hello";
// 	const char	*accept = "jfkhpell";

// 	printf("%zu\n", ft_strspn(s, accept));
// }
