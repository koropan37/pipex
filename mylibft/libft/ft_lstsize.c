/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:53:31 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:06:44 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != 0)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>

// int main()
// {
// 	t_list *node = ft_lstnew(NULL);
// 	t_list *node2 = ft_lstnew("World");
// 	t_list *node3 = ft_lstnew("Hello");

// 	ft_lstadd_front(&node, node2);
// 	ft_lstadd_front(&node, node3);

// 	int n = ft_lstsize(node);

// 	printf("%d\n", n);
// 		return 0;
// }
