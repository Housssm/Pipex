/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:03:57 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/24 17:04:37 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	choose_dup(t_data *data, size_t n)
{
	if (n == 0)
	{
		dup2(data->in_fd, STDIN_FILENO);
		close(data->in_fd);
		close(data->out_fd);
		dup2(data->pip[n][1], STDOUT_FILENO);
		close(data->pip[n][1]);
	}
	else if (n == (data->ac - 1))
	{
		dup2(data->pip[n - 1][0], STDIN_FILENO);
		close(data->pip[n - 1][0]);
		dup2(data->out_fd, STDOUT_FILENO);
		close(data->out_fd);
		close(data->in_fd);
	}
	else
	{
		dup2(data->pip[n -1][0], STDIN_FILENO);
		close(data->pip[n - 1][0]);
		dup2(data->pip[n][1], STDOUT_FILENO);
		close(data->pip[n][1]);
		(close(data->out_fd), close(data->in_fd));
	}
	return ;
}

int	pi_opening(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ac -1)
	{
		if (pipe(data->pip[i]) == -1)
			return (free_all_struct(data), perror("Error 1"), 1);
		i++;
	}
	return (0);
}

int	cmd_excecution(t_data *data, char *av, size_t n)
{
	free_struct(data);
	if (check_path(data, av))
	{
		data->pid[n] = -1;
		return (1);
	}
	data->pid[n] = fork();
	if (data->pid[n] == -1)
		return (free_all_struct(data), perror("Error"), 1);
	if (data->pid[n] == 0)
	{
		closing_pipes(data, n);
		choose_dup(data, n);
		execve(data->path, data->cmd, data->env);
		closing_pipes(data, -1);
		free_all_struct(data);
		perror("execve");
		exit(127);
	}
	return (0);
}

void	run_execution(char **av, t_data *data, int i)
{	
	size_t	j;

	if (data->is_heredoc == 1)
		j = i + 3;
	else
		j = i + 2;
	cmd_excecution(data, av[j], i);
}
