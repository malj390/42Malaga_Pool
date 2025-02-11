/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:28:47 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 14:08:40 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest[] = "dddddddd";
	char	src[] = "sssss";
	unsigned int	srcl;

	printf("Destination: %s\n", dest);
	srcl = ft_strlcpy(dest, src, 3);
	printf("Destination copied: %s\n", dest);
	printf("Src len: %d", srcl);
	return (0);
}
