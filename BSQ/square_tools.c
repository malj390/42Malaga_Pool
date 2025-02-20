/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_tools.c                                     :+:      :+:    :+:   */
/*   By: ergomez- <ergomez-@student.42malaga.com>     +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:24:07 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 18:29:57 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_Square	update_square(int i, int j, int size, t_Square best)
{
	if (size > best.size)
		return ((t_Square){i, j, size});
	return (best);
}

int	compute_dp_cell(int **dp, t_dataMap *data_map, int i, int j)
{
	int	neighbor;

	if (data_map->map[i][j] == data_map->symbols.obstacle)
		return (0);
	if (i == 0 || j == 0)
		return (1);
	neighbor = dp[i - 1][j];
	if (dp[i][j - 1] < neighbor)
		neighbor = dp[i][j - 1];
	if (dp[i - 1][j - 1] < neighbor)
		neighbor = dp[i - 1][j - 1];
	return (neighbor + 1);
}

t_Square	process_map(t_dataMap *data_map, int **dp)
{
	t_Square	best;
	int			i;
	int			j;

	best = (t_Square){0, 0, 0};
	i = 0;
	while (i < data_map->rows)
	{
		j = 0;
		while (j < data_map->cols)
		{
			dp[i][j] = compute_dp_cell(dp, data_map, i, j);
			best = update_square(i, j, dp[i][j], best);
			j++;
		}
		i++;
	}
	return (best);
}

t_Square	find_max_square(t_dataMap *data_map)
{
	t_Square	best;
	int			**dp;

	dp = init_dp_array(data_map->rows, data_map->cols);
	best = process_map(data_map, dp);
	free_array(dp, data_map->rows);
	return (best);
}

void	fill_square(char **map, t_Square square, t_Symbols symbols)
{
	int	i;
	int	j;

	i = square.row - square.size + 1;
	while (i <= square.row)
	{
		j = square.col - square.size + 1;
		while (j <= square.col)
		{
			map[i][j] = symbols.fill;
			j++;
		}
		i++;
	}
}
