/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:51:50 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 19:30:40 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_strcpy( char *dest, char *src );

int	main(void)
{
	//char	str1[];
	//char	str2[];

	char	dest[] = "Flavio";
	char	dest2[] = "Flavio";
	char	src[] = "Gaucho";
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	ft_strcpy(dest, src);
	printf("Destination after copy: %s\n", dest);
	strcpy(dest2, src);
	printf("Destination after copy (oficial): %s\n", dest2);
	return (0);
}
