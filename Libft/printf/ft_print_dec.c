/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:23:35 by hoel-har          #+#    #+#             */
/*   Updated: 2025/12/02 16:15:32 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int		nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr ;
	}	
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

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

int	ft_print_dec(int nb)
{
	int	count;

	ft_putnbr(nb);
	count = ft_size(nb);
	return (count);
}

/*
int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_print_dec(int n)
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
	ft_putstr(result);
	return (size);
}*/