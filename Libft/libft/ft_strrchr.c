/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:25:16 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/10 00:08:33 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int x)
{
	int	i;

	if ((char)x == '\0')
		return ((char *)s + ft_strlen(s));
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char) x)
			return ((char *)&s[i +1]);
		i--;
	}
	return (NULL);
}

/* #define SIZE 40
 
int main(void)
{
  char buffer1[SIZE] = "cpomputer program";
  char * ptr;
  int    ch = 'p';
 
  //ptr = strrchr( buffer1, ch );
  ptr = ft_strrchr( buffer1, ch );
  printf( "The last occurrence of %c in '%s' is '%s'\n",
            ch, buffer1, ptr );
} */
