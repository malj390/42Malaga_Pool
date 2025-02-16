/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:25:26 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 21:50:40 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FUNCTIONS_H"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

int	get_bytes_size(char *str)
{
	char		buffer[1];
	long int	bytesread;
	long int	filesize;
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error! File couldn't be readed.\n");
		return (1);
	}
	filesize = 0;
	bytesread = read(fd, buffer, 1);
	while (bytesread > 0)
	{
		filesize++;
	}
	if (bytesread == -1)
	{
		ft_putstr("Error! Not read byte size from file.\n");
		close(fd);
		return (1);
	}
	close(fd);
	return ((long long)filesize);
}

char	*read_file_to_array(char *filename)
{
	char	*array;
	int		bytesread;
	int		totalread;
	int		fd;
	int		buffer_size;

	buffer_size = get_bytes_size(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file.\n", 21);
		ft_putstr("Make sure numbers.dict is in the current directory.\n");
		return (NULL);
	}
	array = create_dynamic_array(buffer_size);
	totalread = 0;
	bytesread = read(fd, array + totalread, buffer_size)
	while (bytesread > 0)
	{
		totalread = totalread + bytesread;
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
