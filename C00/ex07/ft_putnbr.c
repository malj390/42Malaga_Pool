/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:33:46 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/07 12:16:42 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		putchar(n + '0');
	}
}

int	main(void)
{
	ft_putnbr(-4);
	putchar('\n');
	ft_putnbr(4);
	putchar('\n');
	ft_putnbr(4000);
	putchar('\n');
	ft_putnbr(-4000);
	return (0);
}
