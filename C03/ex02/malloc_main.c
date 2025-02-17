/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:00:05 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 13:00:16 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> // for malloc

char *ft_strcat(char *dest, char *src);

// Function to allocate memory and copy the input string
char *f(const char *input) {
    int len = 0;

    // Calculate the length of the input string
    while (input[len])
        len++;

    // Allocate memory for the string (+1 for null terminator)
    char *new_str = malloc(len + 1);
    if (!new_str)
        return NULL;

    // Copy the input string to new_str
    for (int i = 0; i <= len; i++)
        new_str[i] = input[i];

    return new_str;
}


int	main(void)
{
	//char	dest[4] = "This"; // Changeable array
	//char	*src = "That";	// Non changeable array

	char *dest;
	char *src;
	
	dest = f("This");
	src = f("That");
	printf("%s\n", dest);
	ft_strcat(dest, src);
	printf("%s\n", dest);
	return (0);

}
