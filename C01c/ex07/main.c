/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:44:31 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/06 16:13:44 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

void	print_array(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", *(tab + i));
		i++;
	}
	printf("\n");
}


int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	
	printf("Array in forward:\n");
	print_array(tab, 5);
	printf("Array in reverse:\n");
	ft_rev_int_tab(tab, 5);
	print_array(tab, 5);
	return (0);
}
