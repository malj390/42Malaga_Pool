/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:31:22 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 19:56:11 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dest[] = "Unacadenalarga";
	char	dest2[] = "Unacadenalarga";
	char	src[] = "Copiado";

	printf("Before: %s\n", dest);
	ft_strncpy(dest, src, 9);
	printf("After: %s\n", dest);
	strncpy(dest2, src, 9);
	printf("After (oficial): %s\n", dest2);
	return (0);
}
