/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:59:44 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/07 10:19:46 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	c;

	c = '0'; // '0' Equivalent to 48 in Ascii code (check man ascii)
	while (c <= '9') // '9' equivalent to 58
	{
		write(1, &c, 1);
		++c;
	}
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
