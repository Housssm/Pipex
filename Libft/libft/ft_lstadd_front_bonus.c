/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:30:10 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 15:47:19 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
		new->next = *lst;
		*lst = new;
}

/*int	main()
{
	t_list	*nod1;
	t_list	*nod2;
	t_list	*nod3;

	nod1 = ft_lstnew((void *)"2");
	nod2 = ft_lstnew((void *)"3");
	nod3 = ft_lstnew((void *)"1");
	
	ft_lstadd_front(&nod1, nod3);
	printf("valeur n1 :%d\n",*(char *)nod1->content);
	printf("pointeur n1 vers :%p\n",(void *)nod1->next);
	
	printf("valeur n2 :%s\n", (char *)nod2->content);
	printf("pointeur n2 vers :%p\n", (void*)nod2->next);
	
	printf("valeur n3 :%d\n",*(char *)nod3->content);
	printf("pointeur n3 vers n1:%p\n",(void *)nod3->next);
	
	printf("adresse nod1 :%p\n",(void *)nod1);
	return 0 ;
}*/