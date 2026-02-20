/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:32:05 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/20 12:11:06 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_is_heredoc(int ac, char **av, t_data *data)
{
	if (ac != 6)
		return (perror("Invalid argument\n"), 1);
	else if (access(av[ac - 1], F_OK) != 0)
	{
		data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (data->out_fd == -1)
			return (close(data->out_fd), free_all_struct(data),
				perror("pipex outfil"), 1);
		data->is_heredoc = 1;
	}
	return (0);
}

int	heredoc_struct_attribution(int ac, char **av, char **env, t_data *data)
{
	data->ac = ac;
	data->args = av;
	data->env = env;
	data->in_fd = open(av[1], O_RDONLY);
	data->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (data->out_fd == -1 || data->in_fd == - 1)
		return (close(data->in_fd), free_all_struct(data),
			perror("pipex file"), 1);
	data->cmd[2] = NULL;
	
	
	return (0);
}
int	reading_and_writing(char **av)
{
	// int	fd_read;
	int	fd_write;
	char	*str;
	
	// fd_read = open(STDIN_FILENO, O_RDONLY);
	// if (fd_read == - 1)
	// 	return (close(fd_read), 1);
	fd_write = open("heredoc_tmp", O_WRONLY| O_CREAT| O_APPEND, 0644);
	if (fd_write == - 1)
		return (/* close(fd_read), */ close(fd_write), 1);
	while(1)
	{
		str = get_next_line(0);
		if (!str)
			return (/* close(fd_read), */ close(fd_write), 1);
		if (strncmp(str, av[2], ft_strlen(av[2])) == 0)
		{
			(free(str), /* close(fd_read),  */close(fd_write));
			 break ;
		}		
		ft_putstr_fd(str, fd_write);
		free(str);
	}
	return (0);
}



int	is_heredoc(int ac, char **av, char **env, t_data *data)
{
	(void)env;
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
		return (0);
	if (check_is_heredoc(ac, av, data))
		return (1);
	if (reading_and_writing(av))
		return (1);
	// if (struct_attribution(ac, av, env, data))
	// 	return (1);
	/*supprimer heredoc unlink(".heredoc_tmp");*/	
	return (0);
}


// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	int		fd = open(av[1], O_RDONLY);
// 	char	*str = get_next_line(0);	
// 	while (fd > 0)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break;
// 	}
// 	close(fd);
// 	return (0);
// }
// ouvrir avec gnl sur la stdin, boucler tant que pas de eof (strncmp avec ce qui est ecrit pour voir si ca ne correspond pas au limiter) et stocker dans un fichier cacher. ensuite appliquer la deuxieme commande et retourner dans le fichier de retour puis supprimer le fichier cache 