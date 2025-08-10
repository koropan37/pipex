/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:36:09 by skimura           #+#    #+#             */
/*   Updated: 2025/08/10 17:24:09 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	print_cmd_error(int w_exit_status, char *cmd);
static int	get_exit_status(int status);

int	parent_process(t_pipex *pipex)
{
	int	status;
	int	last_status;
	int	i;

	last_status = 1;
	i = 0;
	safe_close_all(pipex);
	while (i < pipex->cmd->cmd_cnt)
	{
		waitpid(pipex->pids[i], &status, 0);
		if (WIFEXITED(status))
			print_cmd_error(WEXITSTATUS(status), pipex->cmd->cmds[i][0]);
		if (i == pipex->cmd->cmd_cnt - 1)
			last_status = get_exit_status(status);
		i++;
	}
	return (last_status);
}

static void	print_cmd_error(int w_exit_status, char *cmd)
{
	if (w_exit_status == COMMAND_NOT_FOUND)
		ft_dprintf(STDERR_FILENO, "pipex: %s: command not found\n", cmd);
	else if (w_exit_status == PERMISSION_DENIED)
		ft_dprintf(STDERR_FILENO, "pipex: %s: permission denied\n", cmd);
}

static int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (1);
}
