/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:59:51 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 12:59:53 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strcat(char *dest, char *src);

char	*f(char *str)
{
	return (str);
}

int	main(void)
{
	char	dest[4] = "This"; // Changeable array
	char	*src = "That";	// Non changeable array

	printf("%s\n", dest);
	ft_strcat(dest, src);
	printf("%s\n", dest);
	return (0);

}
