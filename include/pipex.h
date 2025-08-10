/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:55:00 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 21:05:14 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../mylibft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define COMMAND_NOT_FOUND 127
# define PERMISSION_DENIED 126
# define OUTFILE_PERMS 0644

typedef struct s_cmd
{
	char	***cmds;
	int		cmd_cnt;
}			t_cmd;

typedef struct s_file
{
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	int		in_err;
	int		out_err;
}			t_file;

typedef struct s_pipex
{
	pid_t	*pids;
	t_file	*file;
	t_cmd	*cmd;
	char	**ep;
	int		pipe_fd[2];
}			t_pipex;

void		init_pipex(t_pipex *pipex, int ac, char *av[], char *ep[]);
void		parse_line(int ac, char *av[]);
//do_pipex
int			do_pipex(t_pipex *pipex);
int			parent_process(t_pipex *pipex);
void		child_process(t_pipex *pipex, int idx);
//path
char		*find_execution_path(t_pipex *pipex, int cmd_idx);
//error
void		error_cmd(t_pipex *pipex);
void		error_pd(t_pipex *pipex);
void		print_alloc_error(void);
void		init_error(t_pipex *pipex);
// free
void		*free_arr(char **arr);
void		free_pipex(t_pipex *pipex);
void		free_pipex_and_err_exit(t_pipex *pipex);
//clean_up
void		clean_up(t_pipex *pipex, char *error_txt);
void		safe_close(int fd);
void		safe_close_all(t_pipex *pipex);

#endif
