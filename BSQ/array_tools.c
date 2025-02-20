/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*   By: ergomez- <ergomez-@student.42malaga.com>     +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:24:19 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 18:30:16 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	**create_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(int));
		i++;
	}
	return (array);
}

void	free_array(int **array, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	**init_dp_array(int rows, int cols)
{
	return (create_array(rows, cols));
}
