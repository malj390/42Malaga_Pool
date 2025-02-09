/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:23:14 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/09 12:41:00 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Esta funcion escribe los caracteres en pantalla
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

// Esta funcion escribe numeros en pantalla tomando integros como argumento
void    ft_putnbr(int n)
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

int my_atoi(char *p) {
  int k = 0;
  while (*p) {
    k = k*10 + (*p) - '0';
    p++;
  }
  return k;
}

int* create_dynamic_array(int size) {
    return (int*)malloc(size * size * 4);  // 4 bytes por cada int
}

void set_value_at(int* array, int row, int col, int size, int value) {
    // Calculamos el índice lineal correspondiente en el array 1D
    array[row * size + col] = value;
}

// Función para imprimir el array en formato 2D
void print_array(int* array, int size) {
    int i = 0, j = 0;
    
    while (i < size) {
        j = 0;
        while (j < size) {
            printf("%d ", array[i * size + j]);  // Accedemos al valor usando la fórmula
            j++;
        }
        printf("\n");
        i++;
    }
}

int	main(int argc, char **argv)
{
	int c;
	int row;
	int col;
	int tmp;	

	int size = 4;
  int* clues = create_dynamic_array(size);  // Crear un array 4x4 dinámico solucion

	c = 1;
	for (row = 0; row < 4; row++) {
    for (col = 0; col < 4; col++) {
        clues[row * size + col] = my_atoi(argv[c]);
        c++;
    }
}
	//}

	print_array(clues, size);

	//c = a1 + a2;
	//ft_putnbr(c);
	//}
	free(clues);
	return (0);
}
