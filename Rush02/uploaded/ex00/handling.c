/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoribio <jtoribio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:44:09 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 23:08:02 by jtoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		n = -n;
		ft_putstr("-");
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
}

unsigned long my_atoi(char *p)
{
	unsigned long k;
	int i;
	
	i = 0;
	k = 0;
	while (p[i] != '\0')
   	{
		k = k * 10 + (p[i]) - '0';
		p++;
	}
	return k;
}

int	count_char(char *str, char target)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == target)
		{
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

void reverse_str(char *str, int len)
{
    int i = 0;
    int j = len - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

char *ft_itoa(int num, char *buffer)
{
    int i = 0;
    int is_negative = 0;

    if (num == 0)
    {
        buffer[i++] = '0';
        buffer[i] = '\0';
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;  // Convertimos a positivo para procesarlo
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0'; // Obtener el último dígito y convertirlo en char
        num /= 10;
    }

    if (is_negative)
        buffer[i++] = '-';

    buffer[i] = '\0';

    reverse_str(buffer, i); // Invertimos la cadena para que quede en orden correcto
    return (buffer);
}