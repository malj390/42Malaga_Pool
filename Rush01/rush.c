#include "FUNCTIONS_H"


void	set_value_at(int* array, int row, int col, int size, int value)
{
	array[row * size + col] = value;
}

void	set_value_at_row_f(int* array, int row, int size, int value)
{
	int col;
	int pr;

	col = 0;
	pr = 0;
	while( col < size)
	{
		array[row * size + col] = value + pr;
		col++;
		pr++;
	}
}

void	set_value_at_row_b(int* array, int row, int size, int value)
{
	int col;
	int pr;

	col = size - 1;
	pr = 0;
	while(col >= 0)
	{
		array[row * size + col] = value + pr;
		col--;
		pr++;
	}
}

void	set_value_at_col_f(int* array, int col, int size, int value)
{
	int row = 0;
	int pr = 0;
    
	while (row < size) 
	{
		array[row * size + col] = value + pr;
		row++;
		pr++;
	}
}

void	set_value_at_col_b(int* array, int col, int size, int value)
{
	int row;
	int pr;

	row = size - 1;
	pr = 0;
	while (row >= 0)
	{  // Loop backwards
		array[row * size + col] = value + pr;
		row--;  // Move upwards
		pr++;
	}
}

void	fill_array(int* array, int size, int value)
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
		set_value_at(array, i, j, size, value);
		j++;
		}
	i++;
	}
}

int	check_height_in_row(int* array, int row, int size, int value)
{
	int col;
	int isthere;

	isthere = 0;  
	col = 0;
	while (col < size)
	{
		if (array[row * size + col] == value)
		{
			isthere = 1;  // Set to 1 if value is found
			break;        // No need to check further
		}
		col++;
	}
	return (isthere);
}

int	check_height_in_col(int* array, int col, int size, int value)
{
	int row;
	int isthere;

	row = 0;
	isthere = 0;
	while (row < size) 
	{
		if (array[row * size + col] == value)
		{
			isthere = 1;
			break;
		}
		row++;
	}
	
	return (isthere);
}
