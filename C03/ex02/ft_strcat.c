/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:02:31 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/13 20:01:55 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while()


}

/*
DESCRIPTION
The  strcat()  function  appends  the  src  string to the dest string, overwriti
ng the terminating null byte
('\0') at the end of dest, and then adds a terminating null byte.  The strings m
ay not overlap, and the dest
string  must  have  enough  space  for  the result.  If dest is not large enough
, program behavior is unpre‐
dictable; buffer overruns are a favorite avenue for attacking secure programs.

The strncat() function is similar, except that

*  it will use at most n bytes from src; and

*  src does not need to be null-terminated if it contains n or more bytes.

As with strcat(), the resulting string in dest is always null-terminated.

If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src
plus  the  terminating  null
byte).  Therefore, the size of dest must be at least strlen(dest)+n+1.

A simple implementation of strncat() might be:

char *
strncat(char *dest, const char *src, size_t n)
{
size_t dest_len = strlen(dest);
size_t i;

for (i = 0 ; i < n && src[i] != '\0' ; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';

return dest;
}

RETURN VALUE
*/
