#include "functions.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
int	main(int argc, char **argv)
{
	if (argc < 2)
			ft_putstr("No map was taken. Please provide one as first argument.\n");
	else
	{
		char *array;
		int	len;
		int	i;
	
		array = read_file_to_array(argv[1]);
		len = count(array);


		i = 0;
	while (i <  len)
	{
		ft_putchar(array[i]);
		i++;
	}

	
	free(array);
	}
	return (0);
}*/

int	main(void) // int argc, char **argv
{
	int rows;
	int cols;
	int i;
	int j;
	char **array;

    rows = 10;
    cols = 10;
    array = create_dynamic_2D_array(rows, cols);
    
    if (array != NULL)
    {
    	while(i <= rows)
    	{
    		while(j <= cols)
    		{
    			array[i][j] = 'A'+ (j % 26);
    			j++;
    		}
    		i++;
    	}

    	while(i <= rows)
    	{
    		array[i][cols] = '\0'; // Null terminate each row
            ft_putstr(array[i]);
            write(1, "\n", 1);
    		i++;
    	}
        free_dynamic_2D_array(array, rows);
    }
}