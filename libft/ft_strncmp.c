/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:27:25 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/23 14:19:58 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t					i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (i < length)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
int	main (void)
{
	char 	s1[]= "test";
	char	s2[]= "";

	printf("resultat : %d", strncmp(s1,s2,4));
	//printf("resultat : %d", ft_strncmp(s1,s2,7));

	return 0;
}*/