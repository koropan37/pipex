/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:26:11 by skimura           #+#    #+#             */
/*   Updated: 2025/07/23 22:00:59 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_check_nl(const char *s);
char	*ft_strjoin_free(char *old, const char *buffer);
char	*gnl_cleanup_internal(char **files);
char	*gnl_process_file(int fd, char **files);

int	ft_check_nl(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin_free(char *old, const char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (free(old), NULL);
	if (!old)
		return (ft_strdup(buffer));
	new = malloc(ft_strlen(old) + ft_strlen(buffer) + 1);
	if (!new)
		return (free(old), NULL);
	i = -1;
	while (old[++i])
		new[i] = old[i];
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(old);
	return (new);
}

char	*gnl_cleanup_internal(char **files)
{
	int	i;

	i = 0;
	while (i < FD_MAX)
	{
		free(files[i]);
		files[i] = NULL;
		i++;
	}
	return (NULL);
}

char	*gnl_process_file(int fd, char **files)
{
	char	*line;

	files[fd] = ft_read_enter(fd, files[fd]);
	if (!files[fd] || !*files[fd])
	{
		free(files[fd]);
		files[fd] = NULL;
		return (NULL);
	}
	line = ft_get_newline(files[fd]);
	if (!line)
	{
		free(files[fd]);
		files[fd] = NULL;
		return (NULL);
	}
	files[fd] = ft_trim_newline(files[fd]);
	return (line);
}
