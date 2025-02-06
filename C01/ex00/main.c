/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:06:05 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/05 13:11:59 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr); // Calling the function ft_ft from ft_ft.c

int	main(void)
{
	int	x;

	x = 0;				// Assign 0 to x
	printf("Before: %d\n", x);	// Print original value stored in x
	ft_ft(&x);			// Sending memory allocation of x to *nbr
	printf("Before: %d\n", x);	// Print changed value hardcoded in ft_ft
	return (0);
}
