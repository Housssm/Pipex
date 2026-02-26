/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:59:23 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:54:33 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	else
	{
		i = i + 1;
		return (i + ft_lstsize(lst -> next));
	}
}
/*
int main(void)
{
	t_list  *nod1;
	t_list  *nod2;
	t_list  *nod3;
	
	nod1 = ft_lstnew((void*)"3");
	nod2 = ft_lstnew((void *)"bonjour");
	nod3 = ft_lstnew((void *)"hello");

	ft_lstadd_front(&nod2, nod3);
	
	printf("%s\n",(char*)nod1->content);
	printf("size: %d\n",ft_lstsize(nod1));

	printf("%s\n",(char*)nod2->content);
	printf("size: %d\n",ft_lstsize(nod2));
	
	printf("%s -> %s\n",(char*)nod3->content, (char*)nod2->content);
	printf("size: %d\n",ft_lstsize(nod3));

	return 0;
	
}*/