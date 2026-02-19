/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:02:20 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/19 10:05:35 by hoel-har         ###   ########.fr       */
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
	else if (access(av[ac - 1], F_OK) != 0)
	{
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->out_fd == -1)
			return (close(data->out_fd), free_all_struct(data),
				perror("pipex outfil"), 1);
	}
	else if (access(av[1], R_OK) != 0 || access(av[ac -1], W_OK) != 0)
		return (perror("pipex 4"), 126);
	return (0);
}

int	pi_intialisation(t_data *data)
{
	size_t	i;

	i = 0;
	data->pip = malloc(sizeof(int *) * (data->ac - 1));
	data->pid = ft_calloc(data->ac, sizeof(pid_t));
	if (!data->pip || !data->pid)
		return (ft_putstr_fd("Error malloc array\n", 2),
			free_all_struct(data), 1);
	while (i < data->ac - 1)
	{
		data->pip[i] = malloc(sizeof(int) * 2);
		if (!data->pip[i])
			return (free_all_struct(data), 1);
		i++;
	}
	return (0);
}

int	struct_attribution(int ac, char **av, char**env, t_data *data)
{	
	data->ac = ac - 3;
	data->env = env;
	if (pi_intialisation(data))
		return (1);
	if (!data->env)
		return (ft_putstr_fd("Error copy env\n", 2), 1);
	data->args = av;
	if (!data->args)
		return (ft_putstr_fd("Error copy args\n", 2), 1);
	data->cmd = NULL;
	data->path = NULL;
	data->in_fd = open(av[1], O_RDONLY);
	if (data->in_fd == -1)
		return (free_all_struct(data), perror("pipex infile"), 1);
	data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->out_fd == -1)
		return (close(data->in_fd), free_all_struct(data),
			perror("pipex outfile"), 1);
	return (0);
}
