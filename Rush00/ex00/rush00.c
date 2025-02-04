/* ************************************************************************** */
/*   rush01.c                                                                 */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*   By: sfedosee <sfefosee@student.42malaga>         +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:52 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/04 18:53:35 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	checkint(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "Error! Please input integers values above 0\n", 44);
	}
}

void	line(int x, char outside1, char inside, char outside2)
{
	int	counter;

	if (x > 1)
	{
		ft_putchar(outside1);
		counter = 1;
		while (counter < x - 1)
		{
			ft_putchar(inside);
			counter++;
		}
		ft_putchar(outside2);
	}
	else
		ft_putchar(outside1);
}

void	rush(int x, int y)
{
	int	counter;

	checkint(x, y);
	if (x > 0 && y > 0)
	{
		if (y == 1)
		{
			line(x, 'o', '-', 'o');
		}
		else
		{
			line(x, 'o', '-', 'o');
			ft_putchar('\n');
			counter = 1;
			while (counter < y - 1)
			{
				line(x, '|', ' ', '|');
				ft_putchar('\n');
				counter++;
			}
			line(x, 'o', '-', 'o');
			ft_putchar('\n');
		}
	}
}
