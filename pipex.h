/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:48 by marvin            #+#    #+#             */
/*   Updated: 2026/02/12 12:10:26 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"

typedef struct s_data
{
	int		pip[2];
	int		pid1;
	int		pid2;
	char	**args;
	char	**cmd;
	char	**env;
	char	*path;
	int		in_fd;
	int		out_fd;
	
}t_data;


#endif