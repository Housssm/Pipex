/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:48 by marvin            #+#    #+#             */
/*   Updated: 2026/02/16 19:37:38 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
#define NB_FD = ac - 1

typedef struct s_data
{
	int		ac;
	int		**pip;
	int		pid1;
	int		**pid;
	int		pid2;
	char	**args;
	char	**cmd;
	char	**env;
	char	*path;
	int		in_fd;
	int		out_fd;

}t_data;

void	free_struct(t_data *data);
char	*ft_strjoin_three(char *s1, char *s2, char *s3);
int		struct_attribution(int ac, char **av, char**env, t_data *data);
int		extract_path(t_data *data, char **full_path, char *av);
int		check_existing_path(t_data *data, char *av);
void	free_all_struct(t_data *data);

#endif