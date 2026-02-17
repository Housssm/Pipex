/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/17 18:05:58 by hoel-har         ###   ########.fr       */
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

void	closing_pipes(t_data *data, size_t n)
{
	size_t	i;

	i = 0;
	while (i < data->ac + 1)
	{
		if (i + 1 != n)
			close(data->pip[i][0]);
		if (i != n)
			close (data->pip[i][1]);
		i++;
	}
}

void	illiterate(t_data *data, size_t n)
{
	if (n == 0)
	{
		dup2(data->in_fd, STDIN_FILENO);
		dup2(data->pip[0][1], STDOUT_FILENO);
	}
	if (n == data->ac)
	{
		dup2(data->pip[n - 1][0], STDIN_FILENO);
		dup2(data->out_fd, STDOUT_FILENO);
	}
	else 
	{
		dup2(data->pip[n -1][0], STDIN_FILENO);
		dup2(data->pip[n][1], STDOUT_FILENO);
	}
}


int	pi_opening(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ac + 1)
	{
		if (pipe(data->pip[i]) == -1)
			return(free_all_struct(data), perror("Error"), 1);
		i++;
	}
	i = 0;
	while (i < data->ac)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			return(free_all_struct(data), perror("Error"), 1);
		i++;	
	}
	return (0);
}




int	all_good(t_data *data, char *av, size_t n)
{
	size_t	i;
	
	i = 0;
	free_struct(data);
	if (check_path(data, av))
		return (1);
	if (data->pid[n] == 0)
	{
		closing_pipes(data, n);
		illiterate(data, n);
		execve(data->path, data->cmd, data->env);
		close(data->pip[i][0]);
		close(data->pip[i + 1][1]);
		// return (0);
	}
	i = 0;
	while (i < data->ac)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
int	main(int ac, char **av, char **env)
{
	t_data		data;
	size_t		i;

	i = 0;
	if (check_errors(ac, av, env))
		return (1);
	if (struct_attribution(ac, av, env, &data))
		return (1);
	if  (pi_opening(&data))
		return (1);
	while(i < (size_t)ac)
	{
		if (all_good(&data, av[i], i))	
			return (1);
		i++;
	}
	free_all_struct(&data);
	return (0);
}



/* int	main(int ac, char **av, char **env)
{
	t_data		data;
	size_t		i;

	i = 0;
	if (check_errors(ac, av, env))
		return (1);
	if (struct_attribution(ac, av, env, &data))
		return (1);
	while(i < (size_t)ac)
	{
		if (all_good(&data,av[i + 2], i))
			return ( free_all_struct(&data), 1);
		i++;
	}
	free_all_struct(&data);
	return (0);
} */
