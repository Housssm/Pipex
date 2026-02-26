/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:14:48 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 15:32:13 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{	
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		idxbeg;
	size_t		idxend;

	i = 0;
	while (s1[i] && ft_isset(s1[i], s2))
			i++;
	idxbeg = i;
	i = ft_strlen(s1) - 1;
	while (ft_isset(s1[i], s2))
		i--;
	idxend = i +1;
	if (idxend < idxbeg)
		idxend = idxbeg;
	str = malloc(sizeof(char) * (idxend - idxbeg + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (idxbeg < idxend)
		str[i++] = (char )s1[idxbeg++];
	str[i] = '\0';
	return (str);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
	{
	char *str = ft_strtrim(av[1], av[2]);
	printf("%s\n", str);
	}
	//free(str);
	return 0;
}*/