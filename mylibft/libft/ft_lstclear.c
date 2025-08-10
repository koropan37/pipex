/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:08:51 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 20:53:20 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

// #include <stdio.h>

// void delete(void *content)
// {
// 	free(content);
// }
// int main()
// {
// 	t_list *first = NULL;
// 	t_list *node1 = ft_lstnew(ft_strdup("World"));
// 	t_list *node2 = ft_lstnew(ft_strdup("Hello"));

// 	ft_lstadd_front(&first, node1);
// 	ft_lstadd_front(&first, node2);

// 	ft_lstclear(&first,delete);
// 	return (0);
// }
