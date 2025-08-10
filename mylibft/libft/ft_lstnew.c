/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:53:23 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:06:37 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlist;

	nlist = (t_list *)malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	nlist->content = content;
	nlist->next = NULL;
	return (nlist);
}

// #include <stdio.h>

// int main()
// {
// 	t_list *node = ft_lstnew("hello");
// 	if(node)
// 	{
// 		printf("%s\n", (char *)node->content);
// 	}
// 	return 0;
// }
