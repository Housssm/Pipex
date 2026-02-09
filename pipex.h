/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:48 by marvin            #+#    #+#             */
/*   Updated: 2026/02/09 17:42:57 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"

typedef struct s_data
{
	int		pip[2];
	char	**args;
	char	**cmd;
	char	**env;
	char	*path;
	int		in_fd;
	int		out_fd;
	
}t_data;


#endif