/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:59:14 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 19:31:22 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*node1 = ft_lstnew("1");
// 	t_list	*node2 = ft_lstnew("World");
// 	t_list	*node3 = ft_lstnew("Hello");
// 	t_list	*all_node;

// 	ft_lstadd_back(&node1, node2);
// 	ft_lstadd_back(&node1, node3);

// 	all_node = node1;

// 	while (all_node)
// 	{
// 		printf("%s\n", (char *)all_node->content);
// 		all_node = all_node->next;
// 	}
// 	t_list	*node4 = NULL;
// 	t_list	*node5 = ft_lstnew("World");
// 	ft_lstadd_back(&node4, node5);
// 	while(node4)
// 	{
// 	printf("%s\n", (char *)node4->content);
// 	node4 = node4->next;
// 	}
// 	return (0);
// }
