/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:08:43 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 20:53:26 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>

// void	change(void *s)
// {
// 	char *str = (char *)s;
// 	while(*str)
// 	{
// 		if('a' <= *str && *str <= 'z')
// 		*str =*str - 32;
// 		str++;
// 	}
// }
// int main()
// {
// 	t_list *first = NULL;
// 	t_list *node1 = ft_lstnew(ft_strdup("World"));

// 	ft_lstadd_front(&first, node1);
// 	ft_lstiter(first, change);
// 	printf("%s\n", (char *)first->content);
// 	return (0);
// }
