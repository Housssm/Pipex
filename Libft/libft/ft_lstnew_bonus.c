/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:24:17 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:54:12 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}

/*int	main()
{
	
	int i = 1;
	char *str = "bonjour"; 
	t_list	*nod1;
	t_list	*nod2;

	nod1 = ft_lstnew(&i);
	nod2 = ft_lstnew(str);
	
	printf("%d\n",*(int *)nod1->content);
	printf("%p\n",(void *)nod1->next);
	
	printf("%s\n", (char *)nod2->content);
	printf("%p\n", (void*)nod2->next);
	
	return 0 ;
}*/