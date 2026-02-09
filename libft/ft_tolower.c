/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:41:34 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/10 19:01:23 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

/*char * strtolower( char * dest, const char * src ) {
    char * result = dest;
    while( (*dest++ = ft_tolower( *src++ )) );
    return result;
}

int main() {

    char * input = "Diego De La Vega 65422#$@^ RGGSR";
    char result[17];

    printf( "Result: %s\n", strtolower( result, input ) );

    return EXIT_SUCCESS;
}*/
