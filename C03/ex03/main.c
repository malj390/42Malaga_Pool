/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:59:09 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 12:59:12 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

char	*f(char *str)
{
	return (str);
}

int	main(void)
{
	char	dest[4] = "This"; // Changeable array
	char	*src = "That";	// Non changeable array

	printf("%s\n", dest);
	ft_strncat(dest, src, 3);
	printf("%s\n", dest);
	return (0);

}
