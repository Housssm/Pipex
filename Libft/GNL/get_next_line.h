/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:35:34 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/19 11:32:27 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 17
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int		count_line(t_list **lst);
// int		ft_strlen(char *str);
t_list	*ft_lst_last(t_list *lst);
char	*is_new_line(char *s, int x);
t_list	*clean_n_return(t_list **lst);
char	*extract_line(t_list **lst);
void	read_to_stash(t_list **lst, int fd);
void	add_to_stash(t_list **lst, char *buffer);
void	clean_all(t_list **lst);
char	*get_next_line(int fd);

#endif