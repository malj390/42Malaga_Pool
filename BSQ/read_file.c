
#include "functions.h"

char	*read_file_to_array(char *filename)
{
	int		bytesread;
	int		totalread;
	int		fd;
	int		buffer_size;
	char	*array;

	buffer_size = get_bytes_size(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file.\n", 21);
		ft_putstr("Make sure numbers.dict is in the current directory.\n");
		return (NULL);
	}
	
	array = create_dynamic_array(buffer_size);
	if (!array)
	{
		close(fd);
		return (NULL);
	}

	totalread = 0;
	bytesread = read(fd, array + totalread, buffer_size);  
	while (bytesread > 0)
	{
		totalread += bytesread;
		bytesread = read(fd, array + totalread, buffer_size); 
	}

	if (bytesread == -1)
	{
		write(2, "Error reading the file\n", 23);
		ft_putstr("Make sure numbers.dict has the proper format\n");
		close(fd);
		return (NULL);
	}
	else
		array[totalread] = '\0';

	close(fd);
	return (array);
}

t_map map;

t_map	read_file_to_tmap(char *filename)
{
	map.array = read_file_to_array(filename);
	map.len = count(map.array);
	map.cols = count_between_targets(map.array, '\n');
	map.rows = count_char(map.array, '\n') - 1;
	map.number[0] = map.array[0];
	map.number[1] = map.array[1];
	map.numberint = my_atoi(map.number);
	map.linesymbol = (char)map.array[2];
	map.obstaclesymbol = (char)map.array[3];
	map.squaresymbol = (char)map.array[4];
	map.arraytrimmed = remove_first_five_positions(map.array);
	map.lentrimmed = count(map.arraytrimmed);
	map.array_2D = convert_1D_to_2D(map.arraytrimmed, map.rows + 1 , map.cols + 1);
	return (map);
}

char	*create_dynamic_array(int size)
{
	char	*array;

	array = (char *)malloc(size + 1);
	if (array == NULL)
	{
		ft_putstr("Error assigning memory\n");
		return (NULL);
	}
	else
		return (array);
}

int	*create_dynamic_arrayint(int size)
{
	int	*array;

	array = (int *)malloc(size + 1);
	if (array == NULL)
	{
		ft_putstr("Error assigning memory\n");
		return (NULL);
	}
	else
		return (array);
}

int get_bytes_size(char *str)
{
    char        buffer[1];
    long int    bytesread;
    long int    filesize;
    int         fd;

    fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("Error! File couldn't be read.\n");
        return (1);
    }

    filesize = 0;
    bytesread = read(fd, buffer, 1);  // Read first byte before entering loop
    while (bytesread > 0)
    {
        filesize++;
        bytesread = read(fd, buffer, 1);  // Read next byte at end of loop
    }

    if (bytesread == -1)
    {
        ft_putstr("Error! Could not read byte size from file.\n");
        close(fd);
        return (1);
    }

    close(fd);
    return ((long long)filesize);
}

char **create_dynamic_2D_array(int rows, int cols)
{
    char **array;
    int i;

    array = (char **)malloc(rows * 8);
    if (array == NULL)
    {
        ft_putstr("Error assigning memory for rows\n");
        return NULL;
    }

    i = 0;
    while (i < rows)
    {
        array[i] = (char *)malloc(cols + 1);
        if (array[i] == NULL)
        {
            ft_putstr("Error assigning memory for a row\n");
            while (i > 0)
            {
                i--;
                free(array[i]);
            }
            
            free(array);
            return NULL;
        }
        i++;
    }

    return array;
}

void free_dynamic_2D_array(char **array, int rows)
{
	int	i;

	i = 0;
    while (i < rows)
    {
        free(array[i]);
        i++;
	}
    free(array);
}

char **convert_1D_to_2D(char *array_1D, int rows, int cols)
{
    char **array_2D = create_dynamic_2D_array(rows, cols);
    if (array_2D == NULL)
    {
        return NULL; 
    }

    int i = 0;
    int j = 0;
    
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            array_2D[i][j] = array_1D[i * cols + j]; 
            j++;
        }
        i++;
    }

    return array_2D;
}

int **create_dynamic_2D_array_int(int rows, int cols)
{
    int **array;
    int i;

    array = (int **)malloc(rows * 8);
    if (array == NULL)
    {
        ft_putstr("Error assigning memory for rows\n");
        return NULL;
    }

    i = 0;
    while (i < rows)
    {
        array[i] = (int *)malloc(cols + 1);
        if (array[i] == NULL)
        {
            ft_putstr("Error assigning memory for a row\n");
            while (i > 0)
            {
                i--;
                free(array[i]);
            }
            
            free(array);
            return NULL;
        }
        i++;
    }

    return array;
}

void free_dynamic_2D_arrayint(int **array, int rows)
{
	int	i;

	i = 0;
    while (i < rows)
    {
        free(array[i]);
        i++;
	}
    free(array);
}
