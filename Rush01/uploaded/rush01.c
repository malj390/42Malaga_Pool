/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:39:45 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/09 23:40:50 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*create_dynamic_array(int size)
{
	int	*array;

	array = (int*)malloc(size * size * 4);
	if (array == NULL)
	{
		write(1, "Error: No se pudo asignar memoria.\n", 35);
		return NULL;
	}
	return array;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		ft_putchar(' ');
	}
}

void	shift_right(int *row, int size)
{
	int last;
	int i;

	last = row[size - 1];
	i = size - 1;
	while (i > 0)
	{
		row[i] = row[i - 1];
		i--;
	}
	row[0] = last;
}

void	generate_grid(int *grid, int size, int views[16])
{
	int	first_row[size];
	int	shift_start;
	int	shift_count;
	int	row = 0; 
	int col = 0;

	row = 0;
	col = 0;
	while (col < size)
	{
		first_row[col] = (col + 1);
		col++;
	}
	shift_start = 0;
	while (shift_start < size)
	{
		if (views[shift_start] == 4)
			break;
		shift_start++;
	}
	shift_count = 0;
	while (shift_count < shift_start)
	{
		shift_right(first_row, size);
		shift_count++;
	}
	col = 0;
	while (col < size)
	{
		grid[col] = first_row[col];
		col++;
	}
	row = 1;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			grid[row * size + col] = grid[(row - 1) * size + (col + 1) % size];
			col++;
		}
		row++;
	}
}

void	print_grid(int *grid, int size) 
{
	int	i;
	int	v;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			v = grid[i * size + j];
			ft_putnbr(v);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int my_atoi(char *p)
{
	int k;

	k = 0;
	while (*p) {
		k = k * 10 + (*p) - '0';
		p++;
	}
	return k;
}

void store_args(int *clues, char **argv, int size) {
	int i;

	i = 0;
	while (i < size) 
    {
		clues[i] = my_atoi(argv[i + 1]);
		i++;
	}
}

int main(int argc, char **argv) {
	int size;

	size = 4;
	if (argc != 17) 
    {
		write(1, "Error: Expected 16 numbers as arguments.\n", 41);
		return 1;
	}

	int *clues = create_dynamic_array(size);
	int *grid = create_dynamic_array(size);

	if (clues == NULL || grid == NULL) {
		return 1;
	}
	store_args(clues, argv, 16);
	generate_grid(grid, size, clues);
	print_grid(grid, size);
	free(clues);
	free(grid);
	return (0);
}
