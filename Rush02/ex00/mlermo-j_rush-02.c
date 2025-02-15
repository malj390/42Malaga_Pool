/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlermo-j_rush-02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:31:13 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/15 19:53:32 by mlermo-j         ###   ########.fr       */
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

int get_bytes_size(char *str)
{
	char buffer[1];
    long int bytesRead;
    long int fileSize;
	int fd;

	fd = open(str, O_RDONLY);
    if (fd == -1) {
        ft_putstr("Error! File could't be readed.\n");
        return (1);
    }

    fileSize = 0;

    while ((bytesRead = read(fd, buffer, 1)) > 0) 
    {
        fileSize++;
    }

    if (bytesRead == -1) {
        ft_putstr("Error! Not read byte size from file.\n");
        close(fd);
        return 1;
    }
    close(fd);
    return ((long long)fileSize); 
}

char *read_file_to_array(char *filename) 
{
	int bytesRead;
    int totalRead;
    int fd;
    int buffer_size;
    char *array;

    buffer_size = get_bytes_size(filename);
    fd = open(filename, O_RDONLY);  
    if (fd == -1) 
    {
        write(2, "Error opening file.\n", 21);
        ft_putstr("Make sure numbers.dict is in the current directory.\n");
        return (NULL); 
    }

    array = create_dynamic_array(buffer_size);
    totalRead = 0;
    while ((bytesRead = read(fd, array + totalRead, buffer_size)) > 0) {
        totalRead = totalRead + bytesRead;  
    }

    if (bytesRead == -1) 
    {
        write(2, "Error reading the file\n", 23);
        ft_putstr("Make sure numbers.dict has the proper format\n");
        close(fd);  // Close the file before returning
        return NULL;
    }
    else
    	array[totalRead] = '\0';

    // Esta linea es solo para comprobar que lee bien el archivo
    //write(1, array, totalRead);

    close(fd);  
    return array; 
}

int count_char(char *str, char target) {
    int count = 0;
    
    while (*str) 
    {
        if (*str == target) {
            count++;
        }
        str++;
    }

    return (count + 1);
}

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

void remove_spaces(char *str) {
    int i;
    int j;

	i = 0;
	j = 0;
    while (str[i] != '\0') 
    {
        if (str[i] != ' ') 
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    
    str[j] = '\0';
}

void split_lines_and_key_value(char *str) {
    int start = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n' || str[i+1] == '\0') 
        { 
        	int end;
        	int len;
        	char *line;
        	int j;
        	int k;
        	int colon_pos;

			if (str[i+1] == '\0') 
			    end = i;
			else 
			    end = i - 1;

            
            len = end - start + 1;
            
            line = create_dynamic_array(len + 1);
            
            j = 0;
            k = 0;

            k = start;
			while (k <= end) {
			    line[j] = str[k];
			    k++;
			    j++;
			}

            line[j] = '\0';  
            start = i + 1; 

            colon_pos = -1;
			k = 0;
			while (k < len) {
			    if (line[k] == ':') {
			        colon_pos = k;
			        break;
			    }
			    k++;
			}

			char *key;
			char *value;
            if (colon_pos != -1) {
                line[colon_pos] = '\0';
                key = line;
                value = &line[colon_pos + 1];

                ft_putstr("Key: ");
                ft_putstr(key);
                ft_putstr(" - Value: ");
                ft_putstr(value);
                ft_putchar('\n');
            }
            free(line);
        }
        i++;
    }
}

int digit_len(char *str)
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
	while (str[i] != 0)
	{
		if ( i == 0 || str[i - 1] == '\n')
		{
			dig_len = digit_len(&str[i]);
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
	int c;

	i = 0;
	
	filename = "numbers.dict";
	array = read_file_to_array(filename);

    remove_spaces(array);
    
    c = count_char(array, '\n') - 1;



    digits = split_digits(array);
	text = split_text(array);

	while( i < c)
	{
		ft_putstr(digits[i]);
		ft_putchar(' ');
		ft_putstr(text[i]);
		ft_putchar('\n');
		i++;
	}

	i = 0;
	free(array);

	while( i <  c) // esto tendría que ser para el tamaño de lineas del diccionario !!
	{

		free(digits[i]);
		free(text[i]);
		i++;
	}
	free(digits);

    return 0;
}

