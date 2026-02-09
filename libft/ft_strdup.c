/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:50:38 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:48:14 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*s;
	char			*dest;
	int				i;

	i = 0;
	s = (char *)str;
	dest = malloc(sizeof(char) * ft_strlen((const char *)s) + 1);
	if (dest == NULL)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main (void)
{
	char *sourco = "Bonjour je manges du pain";

	printf("eux: %s\n", strdup(sourco));
	printf("moi: %s\n", ft_strdup(sourco));
	return 0;
}*/