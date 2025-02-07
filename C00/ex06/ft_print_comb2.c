/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:11:23 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/07 10:15:35 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_digits(char a, char b)
{
	char	i;
	char	j;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, " ", 1);
			write(1, &i, 1);
			write(1, &j, 1);
			write(1, ", ", 3);
			j++;
		}
		i++;
	}
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '8')
		{
			ft_first_digits(i, j);
			j++;
		}
		i++;
	}
}
int	main(void)
{
	ft_print_comb2();
	return (0);
}
