/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:05:05 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/23 15:21:33 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	extract_path(t_data *data, char **full_path, char *av)
{
	char	*str;

	int (i) = 0;
	int (verif) = 1;
	data->cmd = ft_split(av, ' ');
	if (!data->cmd)
		return (free_all_struct(data), 1);
	if (data->cmd[0] == (void *)0)
		return (1);
	while (full_path[i])
	{	
		str = ft_strjoin_three(full_path[i], "/", data->cmd[0]);
		if (access(str, F_OK | R_OK) == 0)
		{
			data->path = ft_strdup(str);
			if (!data->path)
				return (free_all_struct(data), 1);
			(free(str), verif = 0);
			break ;
		}
		(free(str), i++);
	}
	if (verif == 1)
		return (ft_printf("pipex3: command not found: %s\n", data->cmd[0]), 1);
	return (0);
}

int	check_existing_path(t_data *data, char *av)
{	
	if (ft_strchr(av, '/'))
	{
		data->cmd = ft_split(av, ' ');
		if (!data->cmd)
			return (1);
		if (access(data->cmd[0], F_OK | R_OK) == 0)
		{
			data->path = ft_strdup(data->cmd[0]);
			if (!data->path)
				return (free_split(data->cmd), 1);
			return (0);
		}
		else if (access(data->cmd[0], F_OK | R_OK) != 0)
			return (ft_printf("pipex 22:"
					"no such file or directory: %s\n", av), 1);
	}
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

void	wait_for_pid(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ac)
	{
		if (data->pid[i] > 0)
			waitpid(data->pid[i], NULL, 0);
		i++;
	}
}
