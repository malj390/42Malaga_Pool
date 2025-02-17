/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:59:28 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 16:51:52 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < nb && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
DESCRIPTION
The  strcat()  function appends the src string to the dest string, overwriting t
he terminating
null byte ('\0') at the end of dest, and then adds a terminating null byte.  The
  strings  may
not  overlap, and the dest string must have enough space for the result.  If des
t is not large
enough, program behavior is unpredictable; buffer overruns are a favorite avenue
 for attacking
secure programs.

The strncat() function is similar, except that

*  it will use at most n bytes from src; and

*  src does not need to be null-terminated if it contains n or more bytes.

As with strcat(), the resulting string in dest is always null-terminated.

If  src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src
 plus the ter‐
minating null byte).  Therefore, the size of dest must be at least strlen(dest)+
n+1.

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
