/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:16:00 by hoel-har          #+#    #+#             */
/*   Updated: 2025/11/21 22:48:06 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				dlen;
	size_t				slen;
	size_t				tofill;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	dlen = ft_strlen((const char *)dst);
	slen = ft_strlen((const char *)src);
	tofill = size - dlen - 1;
	i = 0;
	if (dlen >= size)
		return (size + slen);
	else
	{	
		while (src[i] && tofill--)
		{
			dst[dlen + i] = src[i];
			i++;
		}
	}
	dst[dlen + i] = 0;
	return (dlen + slen);
}
/*void test(int size)
{
   char str[] = "0123456789012346579012345679";
   char buffer[12];
	int r ;
	r = strlcat(buffer, str, size);
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
