/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:18:21 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:53:37 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		(f)(current->content);
		current = current->next;
	}
}
/*
void	f(void *content)
{
	content = "42";
	printf(" new content :%s\n", (char *)content);
}

int	main(void)
{
    t_list  *nod1;
	t_list  *nod2;
	t_list  *nod3;

    nod1 = ft_lstnew((void*)"bonjour");
	nod2 = ft_lstnew((void *)"comment");
	nod3 = ft_lstnew((void *)"vas-tu");

	ft_lstadd_front(&nod3, nod2);
    ft_lstadd_front(&nod2, nod1);
	
	ft_lstiter(nod1, f);

	printf("%s\n",(char *)nod1->content);
	printf("%s\n",(char *)nod2->content);
	printf("%s\n",(char *)nod3->content);
	return 0;
}*/