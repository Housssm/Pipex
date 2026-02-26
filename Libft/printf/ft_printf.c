/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:57:21 by hoel-har          #+#    #+#             */
/*   Updated: 2025/12/04 11:21:15 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_first_if(const char *str, int i, va_list args, int *ptr)
{
	if (str[i + 1] == 'X')
		*ptr += ft_print_hexa_upper(va_arg(args, unsigned int));
	else if (str[i + 1] == 'x')
		*ptr += ft_print_hexa_lower(va_arg(args, unsigned int));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		*ptr += ft_print_dec(va_arg(args, int));
	else if (str[i + 1] == 'u')
		*ptr += ft_print_unsigned(va_arg(args, unsigned int));
	else if (str[i + 1] == 'c')
		*ptr += ft_print_char(va_arg(args, int));
	else if (str[i + 1] == 's')
		*ptr += ft_print_str(va_arg(args, char *));
	else if (str[i + 1] == 'p')
		*ptr += ft_print_adress(va_arg(args, void *));
	else if (str[i + 1] == '%')
		*ptr += ft_print_char('%');
}

int	ft_exist(const char *str)
{
	int		i;
	int		j;
	char	*list;

	i = 0;
	list = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (0);
			j = 0;
			while (list[j])
			{
				if (str[i + 1] == list[j])
					return (1);
				j++;
			}
			if (list[j == '\0'])
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str || ft_exist(str) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_first_if(str, i, args, &count);
			i++;
		}
		else
		count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
// int main(void)
// {
// 	// char *str = "k";
// 	printf("hello\n%");
// 	// ft_printf("hello%\n");
// 	return 0;
// }