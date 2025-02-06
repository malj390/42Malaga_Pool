/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:08:15 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/05 16:14:45 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	c;
	int	d;

	c = 0;
	d = 42;
	printf("Before (c and d): %d, %d\n", c, d);
	ft_swap(&c, &d);
	printf("After (c and d): %d, %d", c, d);
	return (0);
}
