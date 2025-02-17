/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:50:57 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 14:24:09 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *ft_strstr(char *str, char *to_find);

/*int	main(void)
{
	char	str[15] = "Un dia soleado "; // Changeable array
	char	to_find[3] = "dia";	// Non changeable array

	printf("Search in: %s\n", str);
	ft_strstr(str, to_find);
	printf("Found at: %s\n", str);
	return (0);
}*/

int main() {
    char str[] = "Un dia soleado";
    char to_find[] = "dia";

    char *result = ft_strstr(str, to_find);

    if (result != NULL) {
        printf("La subcadena '%s' fue encontrada en: '%s' >> %\n", to_find, str, result);
    } else {
        printf("La subcadena '%s' no fue encontrada.\n", to_find);
    }
    return 0;
}
