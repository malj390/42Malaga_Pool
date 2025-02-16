/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtoribio_rush-02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoribio <jtoribio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:31:13 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/15 19:42:00 by jtoribio         ###   ########.fr       */
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

	array[totalRead] = '\0'; // termino el array con un caracter null
    // Esta linea es solo para comprobar que lee bien el archivo (el +1 es por el /0)
    //write(1, array, totalRead + 1); 

    close(fd);  // Close the file descriptor
    return array;  // Return the array containing the file content
}

// Funtion to count the \n (number of lines) of the file
int	count_lines(char *str)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			counter++;
		i++;
	}
	return (i);
}

int count_digits(char *str)
{
	int i;

	i = 0;
	while('0' <= str[i] && str[i] <= '9')
	{
		i++;
	}
	return(i);
}

// function that copies the src string to dest and null terminates the result
char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while(src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	**split_digits(char *str)
{
	int		n_lines;
	char	**big_ptr;
	char	*small_ptr;
	int		i;
	int		dig_len;
	int		j;

	i = 0;
	j = 0;
	n_lines = count_lines(str);
	big_ptr = (char **)malloc(n_lines * 8); // Hacen falta 8 bytes para guardar una direccion de memoria
	while (str[i] != '\0')
	{
		if (i == 0 || str[i - 1] == '\n')
		{
			dig_len = count_digits(&str[i]);
			small_ptr = create_dynamic_array(dig_len + 1);
			big_ptr[j] = small_ptr;
			ft_strncpy(small_ptr, &str[i], dig_len);
			i = i + dig_len - 1; // el -1 es pq hay un i++ justo debajo y no quiero perder un caracter (aunque daría igual)
			j++;
		}
		i++;
	}
	return (big_ptr);
}

int	count_text(char *str)
{
	int	i;

	i = 0;
	while( ' ' <= str[i] && str[i] <= '~')
	{
		i++;
	}
	return(i);
}

char	**split_text(char *str)
{
	int		n_lines;
	int		text_len;
	int		i;
	int		j;
	char	*small_ptr;
	char	**big_ptr;

	i = 0;
	j = 0;
	n_lines = count_lines(str);
	big_ptr = (char **) malloc(n_lines * 8);
	while(str[i] != '\0')
	{
		if (i > 0 && str[i - 1] == ':')
		{
			text_len = count_text(&str[i]);
			small_ptr = create_dynamic_array(text_len + 1);
			big_ptr[j] = small_ptr;
			ft_strncpy(small_ptr, &str[i], text_len);
			i = i + text_len - 1; // el -1 es pq hay un i++ justo debajo y no quiero perder un caracter (aunque daría igual)
			j++;
		}
		i++;
	}
	return (big_ptr);
}

#define BUFFER_SIZE 1024

typedef struct s_dict_entry {
    char *number;
    char *word;
} t_dict_entry;

int main() {

	char	*array;
	char	*filename;
	char	**digits;
	char	**text;
	int		i;

	i = 0;
	filename = "numbers.dict";
	array = create_dynamic_array(BUFFER_SIZE);
    array = read_file_to_array(filename, BUFFER_SIZE, array);
    digits = split_digits(array);
	text = split_text(array);

	while( i < 41)
	{
		ft_putstr(digits[i]);
		ft_putchar(' ');
		ft_putstr(text[i]);
		ft_putchar('\n');
		i++;
	}
	i = 0;
	free(array);
	while( i <  42) // esto tendría que ser para el tamaño de lineas del diccionario !!
	{

		free(digits[i]);
		free(text[i]);
		i++;
	}
	free(digits);

    return 0;
}
