
#include "functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long nb = n; 
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int my_atoi(char *p)
{
	int k;
	int i;
	
	i = 0;
	k = 0;
	while (p[i] != '\0')
   	{
		k = k * 10 + (p[i]) - '0';
		p++;
	}
	return k;
}

int	count_char(char *str, char target)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == target)
		{
			count++;
		}
		str++;
	}
	return (count);
}

int	count_until_char(char *str, char target)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == target)
			break;
		count++;
	}
	return (count);
}


int	count(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int count_between_targets(char *str, char target)
{
    int count;
    int found_first;

    count = 0;
    found_first = 0;

    while (*str)
    {
        if (*str == target)
        {
            if (found_first)
                return count;  
            found_first = 1;  
            count = 0;  
        }
        else if (found_first)
        {
            count++;  
        }
        str++;
    }
    return -1;
}

char* remove_first_five_positions(char *array)
{
	int total_size;
	int	i;

	total_size = count(array);
    char *new_array = create_dynamic_array(total_size - 5);
    if (new_array == NULL)
    {
        return NULL;  // Return NULL if memory allocation fails
    }

    int new_index = 0;

    // Start copying from the 6th position (index 5) to the end
    i = 5;
    while (i < total_size)
    {
        new_array[new_index++] = array[i];
        i++;
    }

    return new_array;
}

void	print_array_1D(char *array, int len)
{	
	int	i;
	i = 0;
	while (i <  len)
	{
		ft_putchar(array[i]);
		i++;
	}
	free(array);
}

void	print_array_2D(char **array, int rows, int cols)
{
	if (array != NULL)
	{
	    ft_putstr("Converted 2D array:\n");
	    
	    int i = 0;
	    while (i < rows)
	    {
	        int j = 0;
	        while (j < cols + 1)
	        {
	            ft_putchar(array[i][j]);
	            j++;
	        }
	        //ft_putstr("\n");
	        i++;
	    }
	    free_dynamic_2D_array(array, rows);
	}
}

void	print_arrayint_2D(int **array, int rows, int cols)
{
	if (array != NULL)
	{
	    ft_putstr("Converted 2D array:\n");
	    
	    int i = 0;
	    while (i < rows)
	    {
	        int j = 0;
	        while (j < cols + 1)
	        {
	            ft_putnbr(array[i][j]);
	            j++;
	        }
	        ft_putstr("\n");
	        i++;
	    }
	    free_dynamic_2D_arrayint(array, rows);
	}
}

int	*ft_sort_int_tab(int *tab, int size)
{
	int	aux;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				aux = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = aux;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (tab);
}


int	get_min(int *array, int size)
{
	int *result;

	result = ft_sort_int_tab(array, size);
	return (result[0]);
}


void	solver(int **array, int rows, int cols)
{
    if (array == NULL)
        return;

    ft_putstr("Solving:\n");

    // Allocate memory for neighbors (ensure it's valid memory)
    int *neighbors = create_dynamic_arrayint(3);
    if (neighbors == NULL)
        return;

    int i = 0;
    while (i < rows)
    {
        int j = 0;
        while (j < cols)
        {
            if (array[i][j] == 'o')
            {
                array[i][j] = 0;
            }
            else 
            {
                // Ensure i and j are within valid ranges before accessing neighbors
                if (i > 0 && i < rows && j > 0 && j < cols)
                {
                    neighbors[0] = array[i - 1][j];   // Top neighbor
                    neighbors[1] = array[i][j - 1];   // Left neighbor
                    neighbors[2] = array[i - 1][j - 1]; // Top-left diagonal neighbor

                    array[i][j] = get_min(neighbors, 3);
                }

                ft_putnbr(array[i][j]);  // Print the number safely
            }
            j++;
        }
        ft_putstr("\n");
        i++;
    }

    free(neighbors);
}

void find_largest_square(char **grid, int rows, int cols)
{
    int **dp;
    int max_size = 0;
    int max_row = 0, max_col = 0;

    // Allocate memory for the DP table
    dp = (int **)malloc(rows * sizeof(int *));
    int i = 0;
    while (i < rows) {
        dp[i] = (int *)malloc(cols * sizeof(int));
        i++;
    }
    // Fill the DP table
    i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            if (grid[i][j] == 'o') {
                dp[i][j] = 0;  // Obstacle, cannot be part of a square
            } else {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // First row or column, max size is 1
                } else {
                    // Apply DP formula
                    int min_value = dp[i-1][j-1];
                    if (dp[i-1][j] < dp[i][j-1]) {
                        if (dp[i-1][j] < min_value) {
                            min_value = dp[i-1][j];
                        }
                    } else {
                        if (dp[i][j-1] < min_value) {
                            min_value = dp[i][j-1];
                        }
                    }
                    dp[i][j] = 1 + min_value;
                }
                // Track maximum square found
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_row = i;
                    max_col = j;
                }
            }
            j++;
        }
        i++;
    }

    printf("Largest square size: %d\n", max_size);
    printf("Bottom-right corner at: (%d, %d)\n", max_row, max_col);
    printf("Top-left corner at: (%d, %d)\n", max_row - max_size + 1, max_col - max_size + 1);
    print_arrayint_2D(dp, rows, cols);

}


int	**transformer(char **array, int rows, int cols)
{
	int **arrayint;

	arrayint = create_dynamic_2D_array_int(rows, cols);

	if (array != NULL)
	{
	    ft_putstr("Transforming:\n");
	    
	    int i = 0;
	    while (i < rows)
	    {
	        int j = 0;
	        while (j < cols + 1)
	        {
	            if(array[i][j] == 'o')
	            	arrayint[i][j] = 0;
	            else
					arrayint[i][j] = 1;
				
				
	            ft_putchar(array[i][j]);
	            j++;
	        }
	        ft_putstr("\n");
	        i++;
	    }
	    free_dynamic_2D_array(array, rows);
	    //free_dynamic_2D_arrayint(arrayint, rows);
	}
	return (arrayint);
}