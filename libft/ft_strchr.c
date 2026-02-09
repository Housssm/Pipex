/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:46:47 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/09 20:22:11 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int x)
{
	int				i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)x)
			return ((char *)(str + i + 1));
		i++;
	}
	if ((char)x == '\0')
		return ((char *)(str + i));
	return (0);
}
/* 
#define SIZE 40
int main(void)
{
//   //char buffer1[SIZE] = "cpomputer program";
   char * ptr;
//   int    ch = 'z';
 
  //ptr = strchr( buffer1, ch );
  ptr = ft_strchr("teste",'\0');
  printf("%s",ptr);
// } */
