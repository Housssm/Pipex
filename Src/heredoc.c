/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:32:05 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/23 11:04:24 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	reading_and_writing(char **av)
{
	int		fd_write;
	char	*str;
	int		len;

	len = ft_strlen(av[2]);
	fd_write = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_write == -1)
		return (close(fd_write), 1);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return (close(fd_write), 1);
		if (strncmp(str, av[2], (len)) == 0 && str[len] == '\n')
		{
			ft_putstr_fd("\0", fd_write);
			(free(str));
			break ;
		}
		else
			ft_putstr_fd(str, fd_write);
		free(str);
	}
	close(fd_write);
	return (0);
}

int	check_is_heredoc(int ac, char **av, t_data *data)
{
	if (ft_strncmp(av[1], "here_doc", 9) != 0)
		return (data->is_heredoc = 0, 0);
	if (ac != 6)
		return (perror("Invalid argument\n"), 1);
	data->is_heredoc = 1;
	if (reading_and_writing(av))
		return (1);
	return (0);
}
