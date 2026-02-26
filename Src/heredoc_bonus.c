/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:32:05 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/24 17:04:53 by hoel-har         ###   ########.fr       */
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

int	check_error_bonus(int ac, char **av, char **env, t_data *data)
{	
	if (ac < 5)
		return (ft_printf("Check arguments\n"), 14);
	else if (check_env(env))
		return (perror("pipex 1"), 1);
	if (data->is_heredoc == 1)
		return (0);
	else if (access(av[1], F_OK) != 0)
		return (perror("pipex 2"), 126);
	else if (access(av[ac - 1], F_OK) != 0)
	{
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->out_fd == -1)
			return (close(data->out_fd), free_all_struct(data),
				perror("pipex outfil"), 1);
		close(data->out_fd);
	}
	else if (access(av[1], R_OK) != 0 || access(av[ac -1], W_OK) != 0)
		return (perror("pipex 4"), 126);
	return (0);
}
// int	main(int ac, char **av, char **env)
// {
// 	t_data		data;
// 	size_t		i;

// 	if (check_is_heredoc(ac, av, &data))
// 		return (1);
// 	data.is_heredoc = 0;
// 	if (check_errors(ac, av, env, &data))
// 		return (1);
// 	if (struct_attribution(ac, av, env, &data))
// 		return (1);
// 	if (pi_opening(&data))
// 		return (1);
// 	i = 0;
// 	while (i < data.ac)
// 	{
// 		run_execution(av, &data, i);
// 		i++;
// 	}
// 	closing_pipes(&data, -1);
// 	close(data.in_fd);
// 	close(data.out_fd);
// 	wait_for_pid(&data);
// 	free_all_struct(&data);
// 	return (0);
// }
