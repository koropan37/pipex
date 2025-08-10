/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:47:05 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:30:50 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			nm_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	nm_size = nmemb * size;
	arr = (unsigned char *)malloc(sizeof(unsigned char) * (nm_size));
	if (!arr)
		return (NULL);
	ft_bzero(arr, nm_size);
	return (arr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	*arr = calloc(5, sizeof(int));
// 	int	*arr2 = ft_calloc(5, sizeof(int));
// 	size_t n = 0;
// 	while(n < 5)
// 	{
// 		printf("%d, %d\n", arr[n], arr2[n]);
// 		n++;
// 	}
// 	free(arr);
// 	free(arr2);
// 	return (0);
// }
