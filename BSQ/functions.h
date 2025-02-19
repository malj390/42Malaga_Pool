/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:45:50 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:29 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 4096

typedef struct s_Square
{
	int	row;
	int	col;
	int	size;
}	t_Square;

typedef struct s_Symbols
{
	char	background;
	char	obstacle;
	char	fill;
}	t_Symbols;

typedef struct s_dataMap
{
	t_Symbols	symbols;
	char		**map;
	int			rows;
	int			cols;
}	t_dataMap;

// analysis.c
t_Symbols	analyze_symbols(char *content, int *i);
int			fill_map(char *content, t_dataMap *data_map, int i);
int			validate_and_fill_row(t_dataMap *data_map, char *content, \
									int start, int row);
int			analyze_map(char *content, t_dataMap *data_map);
int			solver(char *content);
// array_tools.c
int			**create_array(int rows, int cols);
void		free_array(int **array, int rows);
void		free_map(char **map, int rows);
void		print_map(char **map, int rows);
int			**init_dp_array(int rows, int cols);

// square_tools.c
t_Square	update_square(int i, int j, int size, t_Square best);
int			compute_dp_cell(int **dp, t_dataMap *data_map, int i, int j);
t_Square	process_map(t_dataMap *data_map, int **dp);
t_Square	find_max_square(t_dataMap *data_map);
void		fill_square(char **map, t_Square square, t_Symbols symbols);

// utils.c
void		ft_putstr(char *str);
int			my_atoi(char *p);
char		*read_file(char *filename);
char		*read_stdin(void);
int			get_line_length(char *content, int *i);

#endif
