/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:28:47 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/12 15:49:47 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest[] = "dddddddd";
	char	dest2[] = "dddddddd";
	char	src[] = "sssss";
	unsigned int	srcl;
	unsigned int	srcl2;

	printf("Destination: %s\n", dest);
	srcl = ft_strlcpy(dest, src, 3);
	printf("Destination copied: %s\n", dest);
	printf("Src len: %d\n", srcl);
	srcl2 = ft_strlcpy(dest2, src, 3);
	printf("Destination copied (oficial): %s\n", dest2);
	printf("Src len (oficial): %d\n", srcl2);
	return (0);
}
