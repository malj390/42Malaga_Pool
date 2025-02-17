/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:54 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 16:41:35 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest[20] = "ThisThis"; // Changeable array
	char	src[20] = "ThatThat";	// Non changeable array
	unsigned int len;

	printf("Destination: %s\n", dest);
	printf("Source: %s\n", src);
	len = ft_strlcat(dest, src, 12);
	printf("Destination: %s\n", dest);
	printf("Destination len: %d\n", len);
	
	return (0);
}
