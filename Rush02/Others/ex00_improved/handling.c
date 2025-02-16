/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:44:09 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 21:58:07 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FUNCTIONS_H"
#include <fcntl.h>
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

int	my_atoi(char *p)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (p[i] != '\0')
	{
		k = k * 10 + (p[i]) - '0';
		p++;
	}
	return (k);
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
