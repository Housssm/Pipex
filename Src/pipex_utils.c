/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:05:05 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/12 23:05:46 by hoel-har         ###   ########.fr       */
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

int	struct_attribution(char **av, char**env, t_data *data)
{
	data->env = env;
	if (!data->env)
		return (ft_putstr_fd("Error copy env\n", 1), 1);
	data->args = av;
	if (!data->args)
		return (ft_putstr_fd("Error copy args\n", 1), 1);
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
		return (1);
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
			return (free_split(data->cmd),
				ft_putstr_fd("Invalide pathway\n", 1), 1);
	}
	return (0);
}
