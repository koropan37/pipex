/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:55:00 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 20:53:15 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../mylibft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
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
	char		***cmds;
	int			cmd_cnt;

}				t_cmd;

typedef struct s_file
{
	char		*infile;
	char		*outfile;
	int			in_fd;
	int			out_fd;
	int			in_err;
	int			out_err;
}				t_file;

typedef struct s_here_doc
{
	char		*limiter;
	int			tmp_fd;
	char		*tmpfile;
	int			tmp_err;
}				t_here_doc;

typedef struct s_pipex
{
	pid_t		*pids;
	t_file		*file;
	t_cmd		*cmd;
	char		**ep;
	int			**pipes_fd;
	t_here_doc	*heredoc;
}				t_pipex;

// parse
void			parse_line(int ac, char *av[]);
// init
void			init_pipex(t_pipex *pipex, int ac, char *av[], char *ep[]);
void			init_file(t_pipex *pipex, int ac, char *av[]);
void			init_cmd(t_pipex *pipex, int ac, char *av[]);
void			init_pid(t_pipex *pipex);
void			fill_cmds(t_pipex *pipex, char *av[]);
void			init_pipe_fd(t_pipex *pipex);
// alloc error
void			print_alloc_error(void);
void			init_error(t_pipex *pipex);
// do_pipex
int				do_pipex(t_pipex *pipex);
void			normal_mode(t_pipex *pipex);
int				parent_process(t_pipex *pipex);
void			child_process(t_pipex *pipex, int idx);
// here_doc
void			init_here_doc(t_pipex *pipex, char *av[]);
void			here_doc_mode(t_pipex *pipex);
// path
char			*find_execution_path(t_pipex *pipex, int cmd_idx);
char			*ft_getenv(char *ep[], const char *name);
// clean_up
void			clean_up(t_pipex *pipex, char *error_txt);
void			safe_close(int fd);
void			safe_close_all(t_pipex *pipex);
void			error_cmd(t_pipex *pipex);
void			error_pd(t_pipex *pipex);
// free
void			*free_arr(char **arr);
void			free_pipex(t_pipex *pipex);
void			free_pipex_and_err_exit(t_pipex *pipex);
#endif
