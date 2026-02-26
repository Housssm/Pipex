/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:23:53 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/22 16:42:42 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
/*
#include <stdint.h>
#define INT_NUMBER 10

int main() 
{
    int * pointer = (int *) ft_calloc( INT_NUMBER, sizeof(int) );
    assert( pointer != NULL );

    // for (int i = 0; i<INT_NUMBER; i++ ) {
    //     pointer[i] = i;
    // }

	// printf( "%d ", pointer[0] );
	// printf( "%d ", pointer[1] );
	// printf( "%d ", pointer[2] );
	// printf( "%d ", pointer[3] );
	// printf( "%d ", pointer[4] );
	// printf( "%d ", pointer[5] );
	// printf( "%d ", pointer[6] );
	// printf( "%d ", pointer[7] );
	// printf( "%d ", pointer[8] );
	// printf( "%d ", pointer[9] );
    for (int i = 0; i<INT_NUMBER; i++ ) {
         printf( "%d ", pointer[i] );

    }
    printf( "\n" );

    free( pointer);


    return 0;
}*/