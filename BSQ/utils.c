/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:24:34 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 18:40:28 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	my_atoi(char *p)
{
	int	k;
	int	i;
	int	sign;

	k = 0;
	i = 0;
	sign = 1;
	while (p[i] == ' ' || p[i] == '\t' || p[i] == '\n')
		i++;
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			sign = -1;
		i++;
	}
	while (p[i] >= '0' && p[i] <= '9')
	{
		k = k * 10 + (p[i] - '0');
		i++;
	}
	return (k * sign);
}

char	*read_file(char *filename)
{
	int		file;
	int		readed;
	char	*buffer;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	readed = read(file, buffer, BUFFER_SIZE - 1);
	if (readed <= 0)
	{
		free(buffer);
		close(file);
		return (NULL);
	}
	buffer[readed] = '\0';
	close(file);
	return (buffer);
}

char	*read_stdin(void)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(0, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

int	get_line_length(char *content, int *i)
{
	int	start;

	start = *i;
	while (content[*i] != '\n' && content[*i] != '\0')
		(*i)++;
	return (*i - start);
}
