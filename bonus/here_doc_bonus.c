/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 03:24:32 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 18:06:42 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	heredoc_txt(t_pipex *pipex);

void	init_here_doc(t_pipex *pipex, char *av[])
{
	pipex->heredoc = ft_calloc(1, sizeof(t_here_doc));
	if (!pipex->heredoc)
		init_error(pipex);
	pipex->heredoc->limiter = av[2];
	pipex->heredoc->tmp_fd = -1;
	pipex->heredoc->tmpfile = NULL;
}

void	here_doc_mode(t_pipex *pipex)
{
	pipex->heredoc->tmpfile = "/tmp/pipex_tmp_file";
	pipex->heredoc->tmp_fd = open(pipex->heredoc->tmpfile,
			O_CREAT | O_WRONLY | O_TRUNC, OUTFILE_PERMS);
	heredoc_txt(pipex);
	safe_close(pipex->heredoc->tmp_fd);
	pipex->heredoc->tmp_fd = open(pipex->heredoc->tmpfile, O_RDONLY);
	pipex->file->out_fd = open(pipex->file->outfile,
			O_CREAT | O_WRONLY | O_APPEND, OUTFILE_PERMS);
	unlink(pipex->heredoc->tmpfile);
}

static void	heredoc_txt(t_pipex *pipex)
{
	int		len;
	char	*line;

	len = ft_strlen(pipex->heredoc->limiter);
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, pipex->heredoc->limiter, len) == 0
			&& line[len] == '\n')
		{
			free(line);
			break ;
		}
		ft_dprintf(pipex->heredoc->tmp_fd, "%s", line);
		free(line);
	}
	get_next_line(-1);
}
