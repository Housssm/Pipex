/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:02:39 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 13:26:49 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"

/*int	ft_strlen(const void *str)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (s[i])
		i++;
	return (i);
}*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}	
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
// run avc -lsbd
void test(int size)
{
   char str[] = "issam";
   char buffer[]= "abc1234";
   int r ;
	r = strlcpy(buffer, str, size);
   printf("copied '%s' into '%s', length = %d\n", str, buffer, r);
   printf("\n");

}
int main()
{
    test(19);
    test(10);
    test(1);
    test(0);

    
    return 0;
}*/