/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:48 by marvin            #+#    #+#             */
/*   Updated: 2026/02/21 08:30:09 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../GNL/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	size_t	ac;
	pid_t	**pip;
	int		*pid;
	char	**args;
	char	**cmd;
	char	**env;
	char	*path;
	int		in_fd;
	int		out_fd;
	int		is_heredoc;

}t_data;

void	free_struct(t_data *data);
char	*ft_strjoin_three(char *s1, char *s2, char *s3);
// int		struct_attribution(int ac, char **av, char**env, t_data *data, int p);
int		struct_attribution(int ac, char **av, char**env, t_data *data);
int		extract_path(t_data *data, char **full_path, char *av);
int		check_existing_path(t_data *data, char *av);
void	free_all_struct(t_data *data);
void	closing_pipes(t_data *data, size_t n);
int		check_errors(int ac, char **av, char **env, t_data *data);
int		check_path(t_data *data, char *av);
int		check_is_heredoc(int ac, char **av, t_data *data);
int		is_heredoc(int ac, char **av, char **env, t_data *data);
int		cmd_excecution(t_data *data, char *av, size_t n);
int		pi_opening(t_data *data);



#endif