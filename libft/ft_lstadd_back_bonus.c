/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:32:22 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:51:54 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*courant;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			courant = *lst;
			while (courant -> next != NULL)
				courant = courant -> next;
			courant -> next = new;
		}
	}
}

/*int main (void )
{
    t_list *nod1;
    t_list *nod2;
    t_list *nod3;

    nod1 = ft_lstnew((void *)"bonjour");
    nod2 = ft_lstnew((void *)"comment");
    nod3 = ft_lstnew((void *)"vas-tu");

    ft_lstadd_front(&nod2,nod1);
    ft_lstadd_back(&nod1,nod3);
    
    t_list	*courant;

	courant = nod1;
	while (courant != NULL)
	{
        printf("%s ->", (char *)courant->content);
		courant = courant->next;

	}
    return 0;
}*/