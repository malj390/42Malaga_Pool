/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:59:44 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/03 15:09:05 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	short	c;

	c = 48;
	while (c < 58)
	{
		write(1, &c, 1);
		++c;
	}
}

int	main(void)
{
	ex03/ft_print_numbers();
	return (0);
}
