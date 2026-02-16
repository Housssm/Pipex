/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:05:05 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/16 19:41:41 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_data *data)
{
	if (data->path)
	{
		free(data->path);
		data->path = NULL;
	}
	if (data->cmd)
	{
		free_split(data->cmd);
		data->cmd = NULL;
	}
}

void	free_tab(t_data *data)
{
	// faire fonction pour free un tableau de char 
	
}
void	free_all_struct(t_data *data)
{
	int	i;
	free_struct(data);
	if (data->pip)
	{
		i = 0;
		while (i < data->ac)
		{	
			free(data->pip[i]);
			i++;
		}
		free (data->pip);
	}
	//modifier fonction pour free tablerau de char pip et pid
}

char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*result;
	int		i;
	int		j;
	int		size;

	size = ft_strlen((char *)s1)
		+ ft_strlen((char *)s2) + ft_strlen((char *)s3);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	j = 0;
	while (s3[j])
		result[i++] = s3[j++];
	result[i] = '\0';
	return (result);
}

int	struct_attribution(int ac, char **av, char**env, t_data *data)
{	
	int	i;

	i = 0;
	data->ac = ac -4;
	data->env = env;
	data->pip = malloc(sizeof(int *) * (data->ac));
	data->pid = malloc(sizeof(int *) * (data->ac));
	if (!data->pip || !data->pid)
		return (1); // bien free les deux tableau si pb
	while ( i < data->ac -1)
	{
		data->pip[i] = malloc(sizeof(int) * 2);
		if (!data->pip[i])
			return (free_all_struct(data), 1);
		i++;
	}
	if (!data->env)
		return (ft_putstr_fd("Error copy env\n", 2), 1);
	data->args = av;
	if (!data->args)
		return (ft_putstr_fd("Error copy args\n", 2), 1);
	data->cmd = NULL;
	data->path = NULL;
	data->in_fd = open(av[1], O_RDONLY);
	data->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->in_fd < 0)
		return (1);
	return (0);
}

int	extract_path(t_data *data, char **full_path, char *av)
{
	int		i;
	int		verif;
	char	*str;

	i = 0;
	verif = 1;
	data->cmd = ft_split(av, ' ');
	while (full_path[i])
	{
		str = ft_strjoin_three(full_path[i], "/", data->cmd[0]);
		if (access(str, F_OK | R_OK) == 0)
		{
			data->path = ft_strdup(str);
			free(str);
			verif = 0;
			break ;
		}
		i++;
		free(str);
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
			return (ft_printf("pipex: no such file or directory: %s\n", av), 1);
	}
	return (0);
}
