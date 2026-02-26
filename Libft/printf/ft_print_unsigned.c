/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:46:18 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/27 14:16:04 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(unsigned int nb)
{
	long int		nbr;

	nbr = nb;
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

static int	ft_size(unsigned int n)
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

int	ft_print_unsigned(unsigned int nb)
{
	int	count;

	ft_putnbr(nb);
	count = ft_size(nb);
	return (count);
}
