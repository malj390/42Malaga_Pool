/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:34:05 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/06 16:17:29 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	half;

	i = 0;
	temp = 0;
	half = size / 2;
	while (half > 0)
	{
		temp = tab [i];
		tab [i] = tab [size - 1];
		tab [size - 1] = temp;
		half--;
		size--;
		i++;
	}
}
