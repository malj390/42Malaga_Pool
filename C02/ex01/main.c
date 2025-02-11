/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:31:22 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/10 12:57:36 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dest[] = "Unacadenalarga";
	char	src[] = "Copiado";
	printf("%s\n", dest);
	ft_strncpy(dest, src, 9);
	printf("%s", dest);
	return (0);
}
