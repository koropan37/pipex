/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:00:12 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:26 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int main()
// {
// 	t_list *node1 = ft_lstnew("1");
// 	t_list *node2 = ft_lstnew("World");
// 	t_list *node3 = ft_lstnew("Hello");

// 	ft_lstadd_front(&node1, node2);
// 	ft_lstadd_front(&node1, node3);

// 	t_list *all_node = node1;
// 	while (all_node)
// 	{
// 		printf("%s\n", (char *)all_node->content);
// 		all_node = all_node->next;
// 	}
// 	return 0;
// }
