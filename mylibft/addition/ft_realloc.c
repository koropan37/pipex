/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:12:10 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:01:00 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
		return (free(ptr), NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	if (copy_size > 0)
		ft_memcpy(new_ptr, ptr, copy_size);
	return (free(ptr), new_ptr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*new_str;

// 	str = (char *)malloc(10);
// 	if (!str)
// 		return (1);
// 	ft_strcpy(str, "hello");
// 	ft_printf("Before realloc: %s\n", str);
// 	new_str = (char *)ft_realloc(str, 10, 20);
// 	if (!new_str)
// 		return (free(str), 1);
// 	ft_strcat(new_str, " world");
// 	ft_printf("After realloc: %s\n", new_str);
// 	free(new_str);
// 	return (0);
// }
