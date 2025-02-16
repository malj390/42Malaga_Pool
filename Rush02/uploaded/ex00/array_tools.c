/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoribio <jtoribio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:25:26 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 23:00:47 by jtoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
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
	long int	bytesRead;
	long int	fileSize;
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error! File couldn't be readed.\n");
		return (1);
	}
	fileSize = 0;
	while ((bytesRead = read(fd, buffer, 1)) > 0)
	{
		fileSize++;
	}
	if (bytesRead == -1)
	{
		ft_putstr("Error! Not read byte size from file.\n");
		close(fd);
		return (1);
	}
	close(fd);
	return ((long long)fileSize);
}

char	*read_file_to_array(char *filename)
{
	int	bytesRead;
	int	totalRead;
	int	fd;
	int	buffer_size;
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
	totalRead = 0;
	while ((bytesRead = read(fd, array + totalRead, buffer_size)) > 0)
	{
		totalRead = totalRead + bytesRead;
	}
	if (bytesRead == -1)
	{
		write(2, "Error reading the file\n", 23);
		ft_putstr("Make sure numbers.dict has the proper format\n");
		close(fd);
		return (NULL);
	}
	else
		array[totalRead] = '\0';
	close(fd);
	return (array);
}
