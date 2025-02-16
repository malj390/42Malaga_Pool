/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:44:09 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 22:05:16 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FUNCTIONS_H"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

void	remove_spaces(char *str)
{
	int	i;
	int	j;

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

int	count_text(char *str)
{
	int	i;

	i = 0;
	while (' ' <= str[i] && str[i] <= '~')
	{
		i++;
	}
	return (i);
}

void	reverse_str(char *str, int len)
{
	int	i;
	int	j;
	char	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

char	*ft_itoa(int num, char *buffer)
{
	int	i;
	int	is_negative;

	i = 0;
	is_negative = 0;

	if (num == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	if (is_negative)
		buffer[i++] = '-';
		buffer[i] = '\0';
	reverse_str(buffer, i);
	return (buffer);
}
