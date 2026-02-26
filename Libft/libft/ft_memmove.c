/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:07:17 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 16:57:19 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*int	ft_strlen(void *str)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (s[i])
		i++;
	return (i);
}*/

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if ((char *)src < (char *)dest)
	{
		while (size > 0)
		{
			((char *)dest)[size - 1] = ((char *)src)[size - 1];
			size--;
		}
	}
	else
	{
		while (i < size)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#define ELEMENT_COUNT 10

int main() 
{
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

	for( int i=0; i<ELEMENT_COUNT; i++ ) 
	{
        printf( "%d ", data[i] );
    }
    puts( "" );  

	void * source = (void *) data;
    void * destination = (void *) ( data + 1 );
    size_t size = ELEMENT_COUNT * sizeof( int );
    //memmove( destination, source, size );

	ft_memmove(destination, source, size);
	 data[0] = 10;
	for( int i=0; i<ELEMENT_COUNT; i++ ) {
        printf( "%d ", data[i] );}
	  return EXIT_SUCCESS;
}
*/