/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/16 19:42:30 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_errors(int ac, char **av, char **env)
{
	if (ac != 5)
		return (ft_printf("Missing arguments, it should be like this :"
				"./pipex infile cmd1 cmd2 outfile\n"), 14);
	else if ((!env/* && strchr(av[2], '/')) || (!env && strchr(av[3], '/'))*/))
		// return (ft_printf("Missing environement"), 1);
		return (perror("pipex 1"), 1);
	else if (access(av[1], F_OK) != 0)
		// return (ft_printf("pipex: no such file or directory: %s\n", av[1]), 126);
		return (perror("pipex 2"), 126);
	else if (access(av[1], R_OK) != 0 || access(av[4], W_OK != 0))
		return (perror("pipex 3"), 126);
		// return (ft_printf("pipex: permission denied %s\n", av[1]), 126);
	return (0);
}

int	check_path(t_data *data, char *av)
{
	int		i;
	char	**full_path;

	i = 0;
	if (check_existing_path(data, av))
		return (1);
	if (data->path != NULL)
		return (0);
	full_path = NULL;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
		{
			full_path = ft_split(data->env[i] + 5, ':');
			if (!full_path)
				return (free_split(full_path), 1);
			break ;
		}
		i++;
	}
	if (extract_path(data, full_path, av))
		return (free_split(full_path), 1);
	free_split(full_path);
	return (0);
}



// int	opening_pipes(t_data *data, int	n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (pipe(data->pip[i] < 0))
// 			return (perror("pipes"), closing_pipes(data), 1);
// 		i++;
// 	}
// 	return (0);
// }


// int	first_cmd(t_data *data, char *av)
// {
// 	if (pipe(*data->pip) == -1)
// 		return (free_all_struct(data), 1);
// 	if (check_path(data, av))
// 		return (1);
// 	data->pid1 = fork();
// 	if (data->pid1 < 0)
// 		return (free_struct(data), 2);
// 	if (data->pid1 == 0)
// 	{
// 		dup2(data->in_fd, STDIN_FILENO);
// 		dup2(data->pip[0][1], STDOUT_FILENO);
// 		close(data->pip[0][0]);
// 		close(data->pip[0][1]);
// 		close(data->in_fd);
// 		execve(data->path, data->cmd, data->env);
// 		perror("execve cmd");
// 		exit(1);
// 	}
// 	close(data->pip[0][1]);
// 	close(data->in_fd);
// 	return (0);
// }
// int	medium_cmd(t_data *data, char *av, int n)
// {
// 	
// 	free_struct(data);
// 	if (check_path(data, av))
// 		return (1);
// 	data->pidn = fork();
// 	if (data->pid2 < 0)
// 		return (free_struct(data), 3);
// 	if (data->pid2 == 0)
// 	{
// 		dup2(data->pip[n][0], STDIN_FILENO);
// 		dup2(data->out_fd, STDOUT_FILENO);
// 		close(data->pip[n][0]);
// 		close(data->pip[n][1]);
// 		close(data->out_fd);
// 		execve(data->path, data->cmd, data->env);
// 		perror("execve cmd2");
// 		exit(1);
// 	}

// 	return (0);
// }

// int	second_cmd(t_data *data, char *av, int n)
// {
// 	printf("arg = %s, n = %d\n\n", av, n);
// 	free_struct(data);
// 	if (check_path(data, av))
// 		return (1);
// 	data->pid2 = fork();
// 	if (data->pid2 < 0)
// 		return (free_struct(data), 3);
// 	if (data->pid2 == 0)
// 	{
// 		dup2(data->pip[n -1][0], STDIN_FILENO);
// 		dup2(data->out_fd, STDOUT_FILENO);
// 		close(data->pip[n][0]);
// 		close(data->pip[n][1]);
// 		close(data->out_fd);
// 		execve(data->path, data->cmd, data->env);
// 		perror("execve cmd2");
// 		exit(1);
// 	}	
// 	close(data->pip[n][0]);
// 	close(data->out_fd);
// 	waitpid(data->pid1, NULL, 0);
// 	waitpid(data->pid2, NULL, 0);
// 	return (0);
// }
void	closing_pipes(t_data *data, int n)
{
	size_t	i;

	i = 0;
	while (i < data->ac)
	{
		if (i + 1 != n)
			close(data->pip[i][0]);
		if (i != n)
			close (data->pip[i][1]);
		i++;
	}
}

void	illiterate(t_data *data, int n)
{
	if (n = 0)
	{
		dup2(data->in_fd, STDIN_FILENO);
		dup2(data->pip[0][1], STDOUT_FILENO);
	}
	if (n =- data->ac)
	{
		dup2(data->pip[n - 1][0], STDIN_FILENO);
		dup2(data->out_fd, STDOUT_FILENO);
	}
	else 
	{
		dup2(data->pip[n -1][0], STDIN_FILENO);
		dup2(data->pip[n], STDOUT_FILENO);
	}
}

int	all_good(t_data *data, char *av, int n)
{
	size_t	i;
	int		pid;

	i = 0;
	while (i < data->ac)
	{
		pid[i]  = fork(); // faire une bouvclepour initialiser tout les pid
		if (pid < 0)
			return( free_all_struct(data), 1);
		if (pid == 0)
		{
			illiterate(data, i);
			closing_pipes(data, i);
			execve(data->path, data->cmd, data->env);
			perror("execve");
			exit(1);
		}
		i++;
		// quel waitpid je dois mettre en compte 
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		pid1;
	int		i;

	pid1 = 0;
	i = 0;
	if (check_errors(ac, av, env))
		return (1);
	if (struct_attribution(ac, av, env, &data))
		return (1);
	// if (first_cmd(&data, av[2]))
	// 	return (free_all_struct(&data), 1);
/* 	while ( i < ac)
	{
		if (medium_cmd(&data, av[i]))
			return (free_struct(&data), 1);
		i++;
	}
//  */	if (second_cmd(&data, av[ac -2], data.ac))
// 		return (free_all_struct(&data), 1);
	free_all_struct(&data);
	return (0);
}
