/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:53:52 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/15 12:07:00 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *bloc1, const void *bloc2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)bloc1;
	s2 = (unsigned char *)bloc2;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	return (0);
}

/*
int main() 
{

    int array1 [] = { 54, 14, 20, 63, 21 };
    int array2 [] = { 54, 95, 20, 63, 21 };
    size_t size = sizeof( int ) * 5;

   
	 printf("or 1 : %d\n", memcmp( array1, array2, size));
	 printf("me 1 : %d\n",ft_memcmp( array1, array2, size) );       
    
    
    
    return 0;
}*/