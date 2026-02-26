/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:48:01 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:53:26 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(del)(lst->content);
		free(lst);
	}
}
/*
void del(void *content)
{
  (void)(content);
}


int 	main(void)
{
	t_list  *nod1;
	t_list  *nod2;
	t_list  *nod3;
	
	nod1 = ft_lstnew("Bonjour");
	nod2 = ft_lstnew("comment");
	nod3 = ft_lstnew("vas-tu");

	ft_lstadd_front(&nod3, nod2);
    ft_lstadd_front(&nod2, nod1);
	t_list *nod4 = ft_lstlast(nod1);
	printf("avant: %s\n",(char *)nod4->content);
	 ft_lstdelone(nod3,del );
	 nod2->next = NULL;
	
	nod4 = ft_lstlast(nod1);
	//printf("%p\n", nod4);

	printf("apres: %s\n",(char *)nod4->content);
	free(nod2);
	free(nod1);
	
}*/