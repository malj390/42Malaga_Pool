/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:23:51 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 18:40:18 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_Symbols	analyze_symbols(char *content, int *i)
{
	int			index;
	t_Symbols	symbols;

	index = 0;
	while (content[index] >= '0' && content[index] <= '9')
		index++;
	symbols = (t_Symbols){content[index], \
	content[index + 1], content[index + 2]};
	*i = index + 4;
	return (symbols);
}

int	fill_map(char *content, t_dataMap *data_map, int i)
{
	int	j;
	int	start;
	int	line_length;

	j = 0;
	while (j < data_map->rows)
	{
		start = i;
		line_length = get_line_length(content, &i);
		if (data_map->cols == -1)
			data_map->cols = line_length;
		else if (line_length != data_map->cols)
			return (-1);
		if (validate_and_fill_row(data_map, content, start, j) == -1)
			return (-1);
		i++;
		j++;
	}
	return (0);
}

int	validate_and_fill_row(t_dataMap *data_map, \
char *content, int start, int row)
{
	int	k;

	data_map->map[row] = malloc(data_map->cols + 1);
	if (!data_map->map[row])
		return (-1);
	k = 0;
	while (k < data_map->cols)
	{
		if (content[start + k] != data_map->symbols.background && \
			content[start + k] != data_map->symbols.obstacle)
			return (-1);
		data_map->map[row][k] = content[start + k];
		k++;
	}
	data_map->map[row][data_map->cols] = '\0';
	return (0);
}

int	analyze_map(char *content, t_dataMap *data_map)
{
	int	i;

	data_map->rows = my_atoi(content);
	data_map->symbols = analyze_symbols(content, &i);
	data_map->map = malloc(data_map->rows * sizeof(char *));
	data_map->cols = -1;
	if (!data_map->map)
		return (-1);
	return (fill_map(content, data_map, i));
}

int	solver(char *content)
{
	t_dataMap	data_map;
	t_Square	square;

	if (analyze_map(content, &data_map) < 0)
		return (-1);
	square = find_max_square(&data_map);
	fill_square(data_map.map, square, data_map.symbols);
	print_map(data_map.map, data_map.rows);
	free_map(data_map.map, data_map.rows);
	return (0);
}
