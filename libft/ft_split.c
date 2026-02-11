/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:40:04 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/11 12:30:22 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] && str[i] != c)
			i++;
		count++;
	}
	return (count);
}

char	*ft_fill_tab(char *str, int length)
{
	int		i;
	char	*mot;

	i = 0;
	mot = malloc(sizeof(char) * (length + 1));
	if (!mot)
		return (NULL);
	while (i < length)
	{
		mot[i] = str[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{	
		free(tab[i]);
		i++;
	}
	free (tab);
}

char	**ft_final(char **tabl, const char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		k = i;
		while (str[i] && str[i] != c)
			i++;
		if (k < i)
		{
			tabl[j] = ft_fill_tab((char *)str + k, (i - k));
			if (!tabl[j])
				return (free_split(tabl), NULL);
			j++;
		}
	}	
	tabl[j] = NULL;
	return (tabl);
}

char	**ft_split(char const *str, char c)
{
	char	**tabl;

	tabl = malloc(sizeof(char *) * (ft_countwords((char *)str, c) + 1));
	if (!tabl)
		return (NULL);
	tabl = ft_final(tabl, str, c);
	if (!tabl)
		return (NULL);
	return (tabl);
}

/*
int	main(void)
{
	char *str = "hello!";
	char c =' ';
	int  i = 0;
	char ** tabl = ft_split(str, c);

	while (i < ft_countwords(str, c))
	{
		printf("%s\n",tabl[i]);
		i++;
	}

	free_split(tabl);
	return 0;
}
*/