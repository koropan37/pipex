/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:01:13 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 20:53:29 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int main()
// {
// 	t_list *node1 = ft_lstnew(NULL);
// 	t_list *node2 = ft_lstnew("World");
// 	t_list *node3 = ft_lstnew("Hello");

// 	ft_lstadd_front(&node1, node2);
// 	ft_lstadd_front(&node1, node3);

// 	t_list *newnode = ft_lstlast(node1);

// 		while (newnode)
// 	{
// 		printf("%s\n", (char *)newnode->content);
// 		newnode = newnode->next;
// 	}
// 		return 0;
// }
