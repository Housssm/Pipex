/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:37:15 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 16:56:26 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (s2[i] == '\0' )
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0' && (i + j) < len)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <bsd/string.h>
#include <stdlib.h>
int main()
{
	
	 printf("moi: %s\n",ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
		 return 0;

}*/