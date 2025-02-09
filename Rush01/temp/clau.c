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

int	check_visibility(int **grid, int *rules)
{
	int i, j, max, count;
	int line[4];

	i = 0;
	while (i < 4)
	{
		count = 0;
		max = 0;
		j = 0;
		while (j < 4)
		{
			line[j] = grid[j][i];
			j++;
		}
		j = 0;
		while (j < 4)
		{
			if (line[j] > max)
			{
				max = line[j];
				count++;
			}
			j++;
		}
		if (count != rules[i])
			return (0);
		i++;
	}
	return (1);
}

int	solve(int **grid, int row, int col, int *rules)
{
	int num;

	if (row == 4)
		return (check_visibility(grid, rules));
	if (col == 4)
		return (solve(grid, row + 1, 0, rules));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1, rules))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	parse_input(char *str, int *rules)
{
	int i;
	i = 0;
	while (*str && i < 16)
	{
		if (*str >= '1' && *str <= '4')
			rules[i++] = *str - '0';
		str++;
	}
	return (i == 16);
}

int	main(int argc, char **argv)
{
	int **grid;
	int rules[16];
	int i;

	if (argc != 2 || !parse_input(argv[1], rules))
	{
		write_str("Error\n");
		return (1);
	}
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
	if (solve(grid, 0, 0, rules))
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

