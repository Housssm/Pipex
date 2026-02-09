/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:51:50 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 14:58:09 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int				i;
	int				res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((s[i] > 8 && s[i] < 14) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * sign);
}
// int	main(int ac, char **av)

// {
// 	(void)ac;
// 	char *tmp1 = "\t\n\r\v\f  469 \n";

// 	(void)av;
// 	printf("moi : %d\n", ft_atoi((const char*)tmp1));
// 	printf("eux : %d\n", atoi((const char*)tmp1));
// 	// printf("eux : %d\n", atoi(av[1]));
// 	// printf("moi : %d\n", ft_atoi(av[1]));
// 	// printf("moi : %d\n", "\t\n\r\v\f  469 \n");
// 	return 0;

// }