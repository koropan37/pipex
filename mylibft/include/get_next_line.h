/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:26:15 by skimura           #+#    #+#             */
/*   Updated: 2025/08/03 20:02:55 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t	ft_read_buf(int fd, char **buffer);
char	*ft_read_enter(int fd, char *enter);
char	*ft_get_newline(char *enter);
char	*ft_trim_newline(char *enter);

int		ft_check_nl(const char *s);
char	*ft_strjoin_free(char *old, const char *buffer);
char	*gnl_cleanup_internal(char **files);
char	*gnl_process_file(int fd, char **files);
#endif
