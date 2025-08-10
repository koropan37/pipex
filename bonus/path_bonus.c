/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:36:23 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 20:22:33 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static char	*find_cmd_path(char *ep[], const char *cmd);
static char	*join_to_fullpath(char *dir, const char *cmd);
static char	**split_path(char *ep[]);
char		*ft_getenv(char *ep[], const char *name);

char	*find_execution_path(t_pipex *pipex, int cmd_idx)
{
	char	*path;

	path = pipex->cmd->cmds[cmd_idx][0];
	if (ft_strchr(path, '/'))
	{
		if (access(path, F_OK) != 0)
			error_cmd(pipex);
		if (access(path, X_OK) != 0)
			error_pd(pipex);
		return (path);
	}
	path = find_cmd_path(pipex->ep, path);
	if (!path)
		error_cmd(pipex);
	if (access(path, X_OK) != 0)
		error_pd(pipex);
	return (path);
}

static char	*find_cmd_path(char *ep[], const char *cmd)
{
	char	**dirs;
	char	*fullpath;
	int		i;

	dirs = split_path(ep);
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		fullpath = join_to_fullpath(dirs[i], cmd);
		if (!fullpath)
			return (free_arr(dirs), NULL);
		if (access(fullpath, F_OK) == 0)
			return (free_arr(dirs), fullpath);
		free(fullpath);
		i++;
	}
	return (free_arr(dirs), NULL);
}

static char	*join_to_fullpath(char *dir, const char *cmd)
{
	char	*path;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!path)
		return (NULL);
	return (path);
}

static char	**split_path(char *ep[])
{
	char	*env;
	char	**path;

	env = ft_getenv(ep, "PATH");
	path = ft_split(env, ':');
	if (!path)
	{
		path = ft_calloc(sizeof(char *), 2);
		if (!path)
			return (NULL);
		path[0] = ft_strdup(".");
		if (!path[0])
		{
			free(path);
			return (NULL);
		}
		path[1] = NULL;
	}
	return (path);
}

char	*ft_getenv(char *ep[], const char *name)
{
	size_t	name_len;
	int		i;

	name_len = ft_strlen(name);
	i = 0;
	while (ep[i])
	{
		if (ft_strncmp(ep[i], name, name_len) == 0 && ep[i][name_len] == '=')
			return (ep[i] + name_len + 1);
		i++;
	}
	return (NULL);
}
