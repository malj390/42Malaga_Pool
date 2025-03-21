/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoribio <jtoribio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:49:30 by jtoribio          #+#    #+#             */
/*   Updated: 2025/02/16 23:07:57 by jtoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unistd.h>
#include <stdlib.h>

char	*create_dynamic_array(int size);
int get_bytes_size(char *str);
char *read_file_to_array(char *filename); 
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int	nbr);
int count_char(char *str, char target);
int	count_lines(char *str);
void remove_spaces(char *str);
int	count_text(char *str);
int digit_len(char *str);
char	*ft_strncpy(char *dest, char *src, int n);
char	**split_digits(char *str);
char	**split_text(char *str);
void	find_word(char **digits, char **text, char *match,  int len);
unsigned long my_atoi(char *p);
void reverse_str(char *str, int len);
char *ft_itoa(int num, char *buffer);

#endif