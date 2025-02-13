/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:14:19 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/13 18:39:57 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				r;
	unsigned int	i;

	i = 0;
	r = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			r = s1[i] - s2[i];
		i++;
	}
	return (r);
}

/*
DESCRIPTION
The  strcmp()  function compares the two strings s1 and s2.  The locale is not t
aken into account (for a lo‐
cale-aware comparison, see strcoll(3)).  The comparison is done using unsigned c
haracters.

strcmp() returns an integer indicating the result of the comparison, as follows:

• 0, if the s1 and s2 are equal;

• a negative value if s1 is less than s2;

• a positive value if s1 is greater than s2.

The strncmp() function is similar, except it compares only the first (at most) n
 bytes of s1 and s2.

RETURN VALUE
*/
