/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:28:54 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 15:14:53 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (len == 0 || ft_strlen(str) <= start)
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
		return (result);
	}
	result = malloc(sizeof(char) * (get_size((char *)&str[start], len) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(int ac , char **av)
{
	if (ac == 4)
	{
		char *str = ft_substr(av[1], atoi(av[2]), atoi(av[3])) ;
		
		printf("%s\n", str);
		
	}
	free (str);
	return 0;
}*/