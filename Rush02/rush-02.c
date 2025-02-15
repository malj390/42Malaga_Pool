/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:31:13 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/15 11:55:33 by mlermo-j         ###   ########.fr       */
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

#define BUFFER_SIZE 256

int main() {

	char *array;
	int	fd;

    fd = open("numbers.dict", O_RDONLY);
    if (fd == -1) {
		ft_putstr("Error opening file. ");
		ft_putstr("Make sure numbers.dict is in the current directory.\n");
        return 1;
    }

	array = create_dynamic_array(BUFFER_SIZE);

	ssize_t bytesRead;
	int i;

	i = 0;
    // Leer el archivo en fragmentos
    while ((bytesRead = read(fd, array, BUFFER_SIZE)) > 0) 
    {
        //write(1, array, bytesRead);
    }

    if (bytesRead == -1) 
	{
        ft_putstr("Error reading numbers.dict\n");
        free(array);
        close(fd);
        return 1;
	}
    

	free(array);
    close(fd);
    return 0;
}
