/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:23:14 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/09 13:37:39 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Esta funcion escribe los caracteres en pantalla
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Esta funcion escribe numeros en pantalla tomando integros como argumento
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
}

int	my_atoi(char *p)
{
	int	k;

	k = 0;
	while (*p) {
		k = k*10 + (*p) - '0';
		p++;
}
	return k;
}

int*	create_dynamic_array(int size)
{
	return (int*)malloc(size * size * 4);  // 4 bytes por cada int
}

void	set_value_at(int* array, int row, int col, int size, int value)
{
    // Calculamos el índice lineal correspondiente en el array 1D
	array[row * size + col] = value;
}

// Function to parse arguments and store values in the array
void store_args_in_array(int* array, char **argv, int size) {
    int c = 1;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            array[row * size + col] = my_atoi(argv[c]);
            c++;
        }
    }
}

// Función para imprimir el array en formato 2D
void	print_array(int* array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", array[i * size + j]);  // Accedemos al valor usando la fórmula
			j++;
		}
			printf("\n");
			i++;
		}
}

int main(int argc, char **argv) {
    int size = 4;

    if (argc != 17) {  // 16 numbers + program name
        printf("Error: Expected 16 numbers as arguments.\n");
        return 1;
    }

    int* clues = create_dynamic_array(size);
    if (!clues) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    store_args_in_array(clues, argv, size);  // Call the new function
    print_array(clues, size);  // Print the array

    free(clues);
    return 0;
}