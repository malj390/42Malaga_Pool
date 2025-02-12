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
