/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:02:55 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/19 13:42:57 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_line(t_list **lst)
{
	t_list	*temp;
	int		j;
	int		count;

	temp = *lst;
	j = 0;
	count = 0;
	while (temp != NULL)
	{		
		j = 0;
		while (((char *)temp->content)[j])
		{
			j++;
			if (((char *)temp->content)[j] == '\n')
			{
				j++;
				break ;
			}
		}
		count += j;
		temp = temp->next;
	}
	return (count);
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*is_new_line(char *s, int x)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)x)
			return (&s[i + 1]);
		i++;
	}
	return (NULL);
}

t_list	*ft_lst_last(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	clean_all(t_list **lst)
{
	t_list	*temp;

	while ((*lst))
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free((*lst));
		*lst = temp;
	}
}
