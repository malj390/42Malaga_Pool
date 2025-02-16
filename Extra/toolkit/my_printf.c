/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:10:59 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/14 11:36:51 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb = n;  // Convert to long to avoid overflow
	if (nb < 0)
	{
		putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	putchar((nb % 10) + '0');
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}

int	main(void)
{
	// Directly calling the functions with specific content
	ft_putstr("Hello Alice! Your score is ");
	ft_putnbr(42);  // Hardcoded number
	ft_putstr(".\n");
	
	ft_putstr("Character test: ");
	putchar('X');  // Hardcoded character
	ft_putstr("\n");
	
	ft_putstr("Negative number: ");
	ft_putnbr(-2147483648);  // Hardcoded negative number
	ft_putstr("\n");
	return (0);
}

