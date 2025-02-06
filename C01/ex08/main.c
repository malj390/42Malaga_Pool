/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:44:54 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/06 13:46:11 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

void	print_array(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", *(tab + i));
		i++;
	}
}

int	main(void)
{
	int	size;
	int	tab[4] = {9, 2, 5, 3};

	size = 4;
	printf("Unsorted array:\n");
	print_array(tab, size);
	ft_sort_int_tab(tab, size);
	printf("\nSorted array:\n");
	print_array(tab, size);
	return (0);
}
