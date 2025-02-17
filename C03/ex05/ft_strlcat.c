/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:25:18 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 16:54:39 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	total_len;

	dest_len = word_len(dest);
	src_len = word_len(src);
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while ((size == 0) || (src[i] != '\0' && dest_len + i < size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	total_len = dest_len + src_len;
	return (total_len);
}

/*
DESCRIPTION
The strlcpy() and strlcat() functions copy and concatenate strings respectively.
  They are de‐
signed to be safer, more consistent, and less error prone replacements for strnc
py(3) and
strncat(3).  Unlike those functions, strlcpy() and strlcat() take the full size
of the buffer
(not just the length) and guarantee to NUL-terminate the result (as long as size
 is larger than
0 or, in the case of strlcat(), as long as there is at least one byte free in ds
t).  Note that a
byte for the NUL should be included in size.  Also note that strlcpy() and strlc
at() only oper‐
ate on true “C” strings.  This means that for strlcpy() src must be NUL-term
inated and for
strlcat() both src and dst must be NUL-terminated.

The strlcpy() function copies up to size - 1 characters from the NUL-terminated
string src to
dst, NUL-terminating the result.

The strlcat() function appends the NUL-terminated string src to the end of dst.
 It will append
at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

RETURN VALUES
*/
