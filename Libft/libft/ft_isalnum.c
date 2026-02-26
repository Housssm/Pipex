/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:06:25 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/10 18:56:46 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c >= '0' && c <= '9')
		|| ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 2 )
		printf("%d",ft_isalnum(av[1][0]));
	else
		return 0;
}*/
