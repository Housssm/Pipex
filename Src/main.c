/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/19 09:33:55 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_errors(int ac, char **av, char **env, t_data *data)
{
	if (ac < 5)
		return (ft_printf("Missing arguments, it should be like this :"
				"./pipex infile cmd1 ... cmdn outfile\n"), 14);
	else if ((!env))
		return (perror("pipex 1"), 1);
	else if (access(av[1], F_OK) != 0)
		return (perror("pipex 2"), 126);
	else if(access(av[ac -1], F_OK) != 0)
	{
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->out_fd == - 1)
			return (close(data->out_fd),free_all_struct(data), perror("pipex outfil"), 1);
	}
	else if (access(av[1], R_OK) != 0 || access(av[ac -1], W_OK) != 0)
		return (perror("pipex 4"), 126);
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
	if (n == (size_t)(-1))
	{
		while ( i < data->ac - 1)
		{
			close(data->pip[i][0]);
			close(data->pip[i][1]);
			i++;
		}
		return ;
	}
	while (i < data->ac - 1)
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
		close(data->in_fd);//
		dup2(data->pip[n][1], STDOUT_FILENO);
	}
	else if (n == data->ac - 1)
	{
		dup2(data->pip[n - 1][0], STDIN_FILENO);
		dup2(data->out_fd, STDOUT_FILENO);
		close(data->out_fd);//
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
	while (i < data->ac -1)
	{
		if (pipe(data->pip[i]) == -1)
			return(free_all_struct(data), perror("Error 1"), 1);
		i++;
	}
	return (0);
}
void	wait_for_pid(t_data *data, int ac)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ac - 3)
	{
		waitpid(data->pid[i],NULL, 0);
		i++;
	}
}

int	all_good(t_data *data, char *av, size_t n)
{
	free_struct(data);
	if (check_path(data, av))
		return (1);
	data->pid[n] = fork();
	if (data->pid[n] == -1)
		return(free_all_struct(data), perror("Error"), 1);
	if (data->pid[n] == 0)
	{
		closing_pipes(data, n);
		illiterate(data, n);
		execve(data->path, data->cmd, data->env);
		perror("execve");
		exit(1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;
	size_t		i;

	i = 0;
	if (check_errors(ac, av, env, &data))
		return (1);
	if (struct_attribution(ac, av, env, &data))
		return (1);
	if (pi_opening(&data))
		return (1);
	while(i < (size_t)ac - 3)
	{
		if (all_good(&data, av[i + 2], i))	
			return (free_all_struct(&data), 1);
		i++;
	}
	closing_pipes(&data, -1);
	close(data.in_fd);
	close(data.out_fd);
	wait_for_pid(&data, ac);
	free_all_struct(&data);
	return (0);
}
