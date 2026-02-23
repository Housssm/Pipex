/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:42:16 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/23 09:19:29 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing_pipes(t_data *data, size_t n)
{
	size_t	i;

	i = 0;
	if (n == (size_t)(-1))
	{
		while (i < data->ac - 1)
		{
			if (data->pip[i][0] >= 0)
				close(data->pip[i][0]);
			if (data->pip[i][1] >= 0)
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

void	free_tab(t_data *data, int **array)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (i < data->ac - 1)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	free_all_struct(t_data *data)
{
	free_struct(data);
	if (data->pid)
	{
		free(data->pid);
		data->pid = NULL;
	}
	free_tab(data, data->pip);
	close(data->in_fd);
	close(data->out_fd);
	if (data->is_heredoc == 1)
		unlink(".heredoc_tmp");
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
