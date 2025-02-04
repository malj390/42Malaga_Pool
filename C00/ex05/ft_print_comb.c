/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:14:48 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/03 15:08:54 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writing(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				writing(i, j, k);
				if (i < '7' || j < '8' || k < '9')
				{
					write(1, ", ", 2);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	ex05/ft_print_comb();
	return (0);
}
