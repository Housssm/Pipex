/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:49:55 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 15:56:21 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*courant;

	if (!lst)
		return (NULL);
	courant = lst;
	while (courant->next != NULL)
		courant = courant->next;
	return (courant);
}
/*
int main (void)
{
    t_list  *nod1;
	t_list  *nod2;
	t_list  *nod3;
    
    nod1 = ft_lstnew((void*)"Bonjour");
	nod2 = ft_lstnew((void *)"comment");
	nod3 = ft_lstnew((void *)"vas-tu");

	ft_lstadd_front(&nod3, nod2);
    ft_lstadd_front(&nod2, nod1);
	t_list *nod4 = ft_lstlast(nod1);
    

	printf("%s\n",(char *)nod4->content);
	printf("%p\n",(void *)nod4->next);
	return 0;
}*/