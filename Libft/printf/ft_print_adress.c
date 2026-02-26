/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:01:06 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/27 20:14:46 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(void *ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	i += ft_print_str("0x");
	i += ft_print_hexa_lower((unsigned long int)ptr);
	return (i);
}
