/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:41:20 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 22:12:15 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb = n;

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

int	my_atoi(char *p)
{
	int	k;
	int	i;
	int	sign;
	int	sign_count;

	k = 0;
	i = 0;
	sign_count = 0;
	while (p[i] == ' ' || p[i] == '\t' || p[i] == '\n')
		i++;
	while (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			sign = -1;
		sign_count++;
		i++;
	}
	if (sign_count > 0 && (p[i] < '0' || p[i] > '9'))
		return (0);
	while (p[i] >= '0' && p[i] <= '9')
	{
		k = k * 10 + (p[i] - '0');
		i++;
	}
	return (k * sign);
}

int	main(void)
{
	char	*a;
	int	r;


	a = "1";
	r = my_atoi(a) + my_atoi(a);
	ft_putstr("The sum of ");
	ft_putnbr(my_atoi(a));
	ft_putstr(" + ");
	ft_putnbr(my_atoi(a));
	ft_putstr(" is ");
	ft_putnbr(r);
	return (0);
}
