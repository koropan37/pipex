/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:05 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 17:07:12 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*word_stock(char const *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all_malloc(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

static int	in_split(char **str, char const *s, char c, size_t word_total)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (i < word_total)
	{
		while (*s && *s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		str[i] = word_stock(s, word_len);
		if (!str[i])
		{
			free_all_malloc(str, i);
			return (0);
		}
		s += word_len;
		i++;
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_total;
	char	**newstr;

	if (!s)
		return (NULL);
	word_total = count_words(s, c);
	newstr = (char **)ft_calloc(sizeof(char *), (word_total + 1));
	if (!newstr)
		return (NULL);
	if (!in_split(newstr, s, c, word_total))
		return (NULL);
	return (newstr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "wo+rld t+ri+gg+r";
// 	char	c = '+';
// 	char	**str = ft_split(src, c);
// 	int i = 0;
// 	while (str[i])
// 	{
// 		printf("%s", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(str);
// 	return (0);
// }
