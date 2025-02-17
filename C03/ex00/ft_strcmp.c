/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:06:42 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 19:10:24 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
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
