/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/23 09:13:04 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	choose_dup(t_data *data, size_t n)
{
	if (n == 0)
	{
		dup2(data->in_fd, STDIN_FILENO);
		close(data->in_fd);
		close(data->out_fd);//
		dup2(data->pip[n][1], STDOUT_FILENO);
	}
	else if (n == data->ac - 1)
	{
		dup2(data->pip[n - 1][0], STDIN_FILENO);
		dup2(data->out_fd, STDOUT_FILENO);
		close(data->out_fd);
		close(data->in_fd);//
	}
	else
	{
		dup2(data->pip[n -1][0], STDIN_FILENO);
		dup2(data->pip[n][1], STDOUT_FILENO);
		close(data->out_fd);//
		close(data->in_fd);//
	}
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

void	wait_for_pid(t_data *data, int ac)
{
	size_t	i;
	(void)ac;
	i = 0;
	while (i < data->ac)
	{
		waitpid(data->pid[i], NULL, 0);
		i++;
	}
}

int	cmd_excecution(t_data *data, char *av, size_t n)
{
	free_struct(data);
	if (check_path(data, av))
		return (closing_pipes(data, -1), 1);
	data->pid[n] = fork();
	if (data->pid[n] == -1)
		return (free_all_struct(data), perror("Error"), 1);
	if (data->pid[n] == 0)
	{
		closing_pipes(data, n);
		choose_dup(data, n);
		execve(data->path, data->cmd, data->env);
		(closing_pipes(data, -1), free_all_struct(data), perror("execve"));
		exit(127);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;
	size_t		i;
	size_t		j;

	ft_bzero(&data, sizeof(t_data));
	if(check_is_heredoc(ac, av, &data))
		return (1);	
	if (check_errors(ac, av, env, &data))
		return (1);
	if (struct_attribution(ac, av, env, &data, data.is_heredoc))
		return (1);
	if (pi_opening(&data))
		return (1);
	i = 0;
	while (i < data.ac)
	{
		if (data.is_heredoc == 1)
			j = i + 3;
		else 
			j = i + 2;
		if (cmd_excecution(&data, av[j], i))
			return (free_all_struct(&data), 1);
		i++;
	}
	closing_pipes(&data, -1);
	close(data.in_fd);
	close(data.out_fd);
	wait_for_pid(&data, ac);
	free_all_struct(&data);
	if (data.is_heredoc == 1)
		unlink(".heredoc_tmp");
	return (0);
}
