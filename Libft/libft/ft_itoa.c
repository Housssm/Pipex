/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:44:32 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 15:57:01 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	int	size;
	int	nb;

	nb = n;
	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = -nb;
		size += 1;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			size;

	size = ft_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	size--;
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n)
	{	
		result[size] = (ft_abs(n % 10)) + '0';
		n = n / 10;
		size --;
	}
	return (result);
}

// int main (int ac, char **av)
// {

// 	if (ac == 2)
// 	{
// 		char *str = ft_itoa(atoi(av[1]));
// 		printf("%s\n", str);
// 	}
// 	return 0;	
// }