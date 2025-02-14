/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzfizz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:42:00 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/14 13:10:20 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	buzzfizz()
{
	int	i;

	i = 1;
	while(i <= 100)
	{
		if (i % 4 == 0 && i % 7 == 0)
		{
				ft_putstr("buzzfizz");
				ft_putstr("\n");
		}
		else
		{
			if (i % 4 == 0 && i % 7 != 0)
			{
				ft_putstr("buzz");
				ft_putstr("\n");
			}
			if (i % 7 == 0 && i % 4 != 0) 
			{
				ft_putstr("fizz");
				ft_putstr("\n");
			}
			if (i % 7 != 0 && i % 4 != 0) 
			{
				ft_putnbr(i);
				ft_putstr("\n");
			}
		}
		i++;
	}
}

int	main(void)
{
	buzzfizz();
	return (0);
}
