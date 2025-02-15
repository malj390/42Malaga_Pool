/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:31:13 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/15 13:27:19 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putnbr(int	nbr)
{
	long	n;

   	n = nbr;
	if (n < 0)
	{
		n = -n;
		ft_putstr("-");
	}

	if ( n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if ( n < 10)
	{
		ft_putchar(n + '0');
	}
}

void	print_grid(char *grid, int size) 
{
	int	i;
	char	v;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			v = grid[i * size];
			ft_putchar(v);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	*create_dynamic_array(int size)
{
	char	*array;

    array = (char *)malloc(size);
    if (array == NULL)
   	{
        ft_putstr("Error assigning memory\n");
        return (NULL);
    }
	else
		return (array);
}

char *read_file_to_array(const char *filename, size_t buffer_size, char *array) 
{
	ssize_t bytesRead;
    size_t totalRead;
    int fd = open(filename, O_RDONLY);  
    if (fd == -1) {
        write(2, "Error opening file.\n", 21);
        ft_putstr("Make sure numbers.dict is in the current directory.\n");
        return (NULL); 
    }

    totalRead = 0;

    while ((bytesRead = read(fd, array + totalRead, buffer_size)) > 0) {
        totalRead = totalRead + bytesRead;  
    }

    if (bytesRead == -1) {
        write(2, "Error reading the file\n", 23);
        ft_putstr("Make sure numbers.dict has the proper format\n");
        close(fd);  // Close the file before returning
        return NULL;
    }

    // Esta linea es solo para comprobar que lee bien el archivo
    //write(1, array, totalRead);

    close(fd);  // Close the file descriptor
    return array;  // Return the array containing the file content
}


#define BUFFER_SIZE 256

typedef struct s_dict_entry {
    char *number;
    char *word;
} t_dict_entry;

int main() {

	char *array;
	char *filename;

	filename = "numbers.dict";
	array = create_dynamic_array(BUFFER_SIZE);
    array = read_file_to_array(filename, BUFFER_SIZE, array);
    

	free(array);

    return 0;
}
