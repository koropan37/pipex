/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:08:10 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 20:53:23 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst && del)
		del(lst->content);
	free(lst);
}

// #include <stdio.h>

// void del(void *content)
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
// 	ft_lstdelone(node1,del);
// 	first->next = NULL;
// 	printf("%s\n",(char *)first->content);
// 	ft_lstdelone(first,del);
// 	return (0);
// }
