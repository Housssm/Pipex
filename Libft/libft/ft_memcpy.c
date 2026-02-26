/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:52:25 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 16:56:07 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	i = 0;
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (destination == NULL && source == NULL)
		return (0);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
/*
int main()
{
    int array[] = {54, 85, 20, 63, 21};
    int copy[5];
     int copyo[5];
    int i = sizeof(int) * 5;
    size_t size= sizeof(int) * 5;

    memcpy( copy, array, size );
for( i=0 ; i<5; i++)
    {
    printf("%d ", copy[i]);}
    printf("\n");

    ft_memcpy(copyo, array, size);

    for( i=0 ; i<5; i++)
    {
    printf("%d ", copyo[i]);}
    printf("\n");
    return (0); 

}
*/