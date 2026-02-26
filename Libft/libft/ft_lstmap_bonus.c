/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:47:47 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 18:18:44 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	void	*content;

	if (!lst && !f && !del)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		current = ft_lstnew(content);
		if (current == NULL)
		{
			ft_lstclear(&head, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&head, current);
		lst = lst->next;
	}
	return (head);
}
/*
 void del(void *content)
{
  (void)(content);
}
void	*f(void *content)
{
	content = "hallo";
	return(content);
}

int	main(void)
{
    t_list  *nod1;
	t_list  *nod2;
	t_list  *nod3;
	t_list	*head;
	t_list	*fct;
    nod1 = ft_lstnew((void*)"bonjour");
	nod2 = ft_lstnew((void *)"comment");
	nod3 = ft_lstnew((void *)"vas-tu");

	ft_lstadd_front(&nod3, nod2);
    ft_lstadd_front(&nod2, nod1);
	
	//head= nod1;
	fct = ft_lstmap(nod1,f,del);
	//int i = 0;
	// while (head!=NULL)
    // {
    //     printf("content : %s\n",(char *)head->content);
    //     head = head->next;
    // }
	int j = 1;
	while (fct!=NULL)
    {
        printf("content : %s, j:%d\n",(char *)fct->content, j++);
        fct = fct->next;
    }
	
	return 0;
}*/