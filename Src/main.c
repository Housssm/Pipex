/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/23 12:44:43 by hoel-har         ###   ########.fr       */
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
	}
	else if (n == (data->ac - 1))
	{
		dup2(data->pip[n - 1][0], STDIN_FILENO);
		dup2(data->out_fd, STDOUT_FILENO);
		close(data->out_fd);
		close(data->in_fd);
	}
	else
	{
		dup2(data->pip[n -1][0], STDIN_FILENO);
		dup2(data->pip[n][1], STDOUT_FILENO);
		close(data->out_fd);
		close(data->in_fd);
	}
	return;
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
		return (1);
	}
	data->pid[n] = fork();
	if (data->pid[n] == -1)
		return (free_all_struct(data), perror("Error"), 1);
	if (data->pid[n] == 0)
	{
		printf("\n\nCHILDS%zu\n\n", n);
		closing_pipes(data, n);
		choose_dup(data, n);
		if (execve(data->path, data->cmd, data->env) == -1)
		{
			ft_putstr_fd("\n\nInside error execve\n\n", 1);
			closing_pipes(data, -1);
			free_all_struct(data);
			perror("execve");
			exit(127);
		}
	}
	else if (data->pid[n] > 0)
	{
		printf("\n\nparent\n\n");
		close(data->in_fd);
		close(data->out_fd);
		wait_for_pid(data);
	}
	return (0);
}
	
int	run_execution(char **av, t_data *data, int i)
{	
	size_t	j;
	
	if (data->is_heredoc == 1)
	j = i + 3;
	else
	j = i + 2;
	if (cmd_excecution(data, av[j], i))
	{
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;
	size_t		i;
	
	if (check_is_heredoc(ac, av, &data))
	return (1);
	if (check_errors(ac, av, env, &data))
	return (1);
	if (struct_attribution(ac, av, env, &data))
	return (1);
	if (pi_opening(&data))
	return (1);
	i = 0;
	while (i < data.ac)
	{
		if (run_execution(av, &data, i))
			break ;
		i++;
	}
	ft_putstr_fd("\n\nTEST FIN\n\n", 2);
	// close(data.in_fd);
	// close(data.out_fd);
	// wait_for_pid(&data);
	closing_pipes(&data, -1);
	free_all_struct(&data);
	return (0);
}
