#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	char *array;
	char *arraytrimmed;
    char number[2];
    int	numberint;      
    char linesymbol;     
    char obstaclesymbol; 
    char squaresymbol;
    int	len;
    int lentrimmed;
	int	cols;
	int	rows;
	char **array_2D;
} t_map;


char	*read_file_to_array(char *filename);
char	*create_dynamic_array(int size);
int *create_dynamic_arrayint(int size);
int	get_bytes_size(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int	count_char(char *str, char target);
int	count(char *str);
char **create_dynamic_2D_array(int rows, int cols);
void free_dynamic_2D_array(char **array, int rows);
int	count_until_char(char *str, char target);
void	ft_putnbr(int n);
int count_between_targets(char *str, char target);
t_map	read_file_to_tmap(char *filename);
int my_atoi(char *p);
char* remove_first_five_positions(char *array);
char **convert_1D_to_2D(char *array_1D, int rows, int cols);
void	print_array_1D(char *array, int len);
void	print_array_2D(char **array, int rows, int cols);
void    solver(int **array, int rows, int cols);
int **create_dynamic_2D_array_int(int rows, int cols);
void free_dynamic_2D_arrayint(int **array, int rows);
int **transformer(char **array, int rows, int cols);
void find_largest_square(char **grid, int rows, int cols);


#endif