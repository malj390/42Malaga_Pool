#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_file_to_array(char *filename);
char	*create_dynamic_array(int size);
int	get_bytes_size(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int	count_char(char *str, char target);
int	count(char *str);
char **create_dynamic_2D_array(int rows, int cols);
void free_dynamic_2D_array(char **array, int rows);

#endif