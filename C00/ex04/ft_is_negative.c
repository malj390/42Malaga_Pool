/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:19:24 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/07 12:30:37 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int c)
{
	if (c >= 0)
		write(1, "P", 1);
	else
		write(1, "N", 1);
}

int	main(void)
{
	ft_is_negative(-42);
	write(1, "\n", 1);
	ft_is_negative(0);
	write(1, "\n", 1);
	ft_is_negative(42);
	return (0);
}
