/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:40:47 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/27 20:13:35 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_upper(unsigned long int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_print_hexa_upper(nb / 16);
	count += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	return (count);
}
