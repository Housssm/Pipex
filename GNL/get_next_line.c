/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:03:57 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/26 15:18:33 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_to_stash(t_list **lst, char *buffer)
{
	t_list	*new;

	if (*lst == NULL)
	{
		(*lst) = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return ;
		(*lst)->content = buffer;
		(*lst)->next = NULL;
	}
	else
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return ;
		new -> content = buffer;
		new -> next = NULL;
		ft_lst_last(*lst)->next = new;
	}
}

void	read_to_stash(t_list **lst, int fd)
{
	char	*buffer;
	int		bytes_reads;

	bytes_reads = 1;
	while (bytes_reads > 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_reads = read(fd, buffer, BUFFER_SIZE);
		if (bytes_reads == 0)
			return (free(buffer));
		if (bytes_reads < 0)
		{
			clean_all(lst);
			free(buffer);
			return ;
		}
		buffer[bytes_reads] = '\0';
		add_to_stash(lst, buffer);
		if (is_new_line(buffer, '\n') != NULL)
			break ;
	}
}

char	*extract_line(t_list **lst)
{
	t_list	*temp;
	char	*result;
	int		i;
	int		j;

	temp = *lst;
	result = malloc(sizeof(char) * (count_line(lst) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (temp != NULL)
	{
		j = 0;
		while (((char *)temp->content)[j])
		{
			result[i++] = ((char *)temp->content)[j++];
			if (result[i - 1] == '\n')
				break ;
		}
		temp = temp->next;
	}
	result[i] = '\0';
	return (result);
}

t_list	*clean_n_return(t_list **lst)
{
	t_list	*temp;
	t_list	*ret;
	char	*rest;
	int		i;
	int		j;

	i = ((j = 0));
	temp = ft_lst_last((*lst));
	while ((((char *)temp->content)[i]) && ((char *)temp->content)[i] != '\n')
		i++;
	if (((char *)temp->content)[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * ft_strlen((char *)temp->content) - i + 1);
	while ((((char *)temp->content)[i]))
		rest[j++] = ((char *)temp->content)[i++];
	rest[j] = '\0';
	clean_all(lst);
	if (rest[0] == '\0')
		return (free(rest), (NULL));
	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (free(rest), (NULL));
	ret->content = rest;
	ret->next = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*result;

	if (fd < 0)
		clean_all(&head);
	result = NULL;
	if (!head || !is_new_line((char *)head->content, '\n'))
		read_to_stash(&head, fd);
	if (!head)
		return (NULL);
	result = extract_line(&head);
	head = clean_n_return(&head);
	if (result && result[0] == '\0')
		return (free(result), (NULL));
	return (result);
}
