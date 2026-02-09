/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:57:58 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/10 19:01:43 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

/*char * strtoupper( char * dest, const char * src ) 
{
    char * result = dest;
    while( (*dest++ = ft_toupper( *src++ )) );
    return result;
}

int main() {

    char * input = "456sfjfdjERLBF6%^#*$^*gjfhjf";
    char result[17];

    printf( "Result: %s\n", strtoupper( result, input ) );

    return EXIT_SUCCESS;
}*/