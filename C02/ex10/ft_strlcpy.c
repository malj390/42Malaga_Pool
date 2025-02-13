/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:51:46 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/12 15:48:41 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;

	srclen = 0;
	while (src[srclen] != '\0')
	{
			srclen++;
	}
	
	if (size == 0)
			return srclen;

	i = 0;
	while (i < size -1 && src[i] != '\0')
	{
		dest[i]	= src[i];
		i++;
	}
	dest[i] = '\0';
	return srclen;
}

/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings respectively.  They are de‐
     signed to be safer, more consistent, and less error prone replacements for strncpy(3) and
     strncat(3).  Unlike those functions, strlcpy() and strlcat() take the full size of the buffer
     (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than
     0 or, in the case of strlcat(), as long as there is at least one byte free in dst).  Note that a
     byte for the NUL should be included in size.  Also note that strlcpy() and strlcat() only oper‐
     ate on true “C” strings.  This means that for strlcpy() src must be NUL-terminated and for
     strlcat() both src and dst must be NUL-terminated.

     The strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to
     dst, NUL-terminating the result.

     The strlcat() function appends the NUL-terminated string src to the end of dst.  It will append
     at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

RETURN VALUES
*/
