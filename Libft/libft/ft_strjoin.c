/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:48:46 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/15 16:27:47 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	int		size;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0 ;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
/*
int	main(int ac, char **av)
{
	char *str = ft_strjoin(av[1], av[2]);

	if (ac == 3)
	{
				printf("%s\n", str);
	}
	free(str);
	return 0;
}*/