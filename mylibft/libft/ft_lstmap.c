/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:10:26 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:36:57 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_cont;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_cont = f(lst->content);
		new_node = ft_lstnew(new_cont);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// #include <stdio.h>

// void	*change(void *s)
// {
// 	char *tmp = (char *)s;
// 	char *str = ft_strdup(tmp);
// 	char *ret = str;
// 	if(!str)
// 	return (NULL);
// 	while(*str)
// 	{
// 		if('a' <= *str && *str <= 'z')
// 		*str -= 32;
// 		str++;
// 	}
// 	return (ret);
// }

// void del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list *first = NULL;
// 	ft_lstadd_back(&first,ft_lstnew(ft_strdup("hello")));

// 	t_list *map = ft_lstmap(first, change, del);
// 	t_list *tmp = map;
// 	while(tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&first, del);
// 	ft_lstclear(&map, del);
// 	return (0);
// }
