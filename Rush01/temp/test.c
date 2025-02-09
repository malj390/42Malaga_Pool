#include <unistd.h>
#include <stdlib.h>
void	write_char(char c)
{
	write(1, &c, 1);
}
void	write_str(char *str)
{
	while (*str)
	{
		write_char(*str);
		str++;
	}
}
void	write_number(int n)
{
	char c;
	c = n + '0';
	write_char(c);
}
void	print_grid(int **grid)
{
	int i;
	int j;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write_number(grid[i][j]);
			if (j < 3)
				write_char(' ');
			j++;
		}
		write_char('\n');
		i++;
	}
}
int	is_valid(int **grid, int row, int col, int num)
{
	int i;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
int	solve(int **grid, int pos)
{
	int row;
	int col;
	int num;
	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
int	main(void)
{
	int **grid;
	int i;
	grid = (int **)malloc(4 * sizeof(int *));
	if (!grid)
		return (1);
	i = 0;
	while (i < 4)
	{
		grid[i] = (int *)malloc(4 * sizeof(int));
		if (!grid[i])
			return (1);
		i++;
	}
	if (solve(grid, 0))
		print_grid(grid);
	else
		write_str("Error\n");
	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (0);
}

