/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoribio <jtoribio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:54:37 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 23:18:31 by jtoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s1[i] != '\0' || s2[i] != '\0' )
	{
		if (s1[i] != s2[i])
			r = s1[i] - s2[i];
		i++;
	}
	return (r);
}

void	find_word(char **digits, char **text, char *match, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(digits[i], match) == 0)
		{
			ft_putstr(text[i]);
			ft_putstr(" ");
		}
		i++;
	}
}

void	ft_print_thousands(int n_div, char **digits, char **text, int lenlines)
{
	char	*ptr;
	int		i;

	i = 1;
	ptr = create_dynamic_array(3 * n_div + 2);
	ptr[0] = '1';
	while (i <= 3 * n_div)
	{
		ptr[i] = '0';
		i++;
	}
	ptr[i] = '\0';
	find_word(digits, text, ptr, lenlines);
	free(ptr);
}

void	ft_put_small_nbr(char *num, char **text, char **digits, int lenlines)
{
	long	len;
	char	*newnum;
	long	n;

	n = my_atoi(num);
	len = digit_len(num);
	newnum = create_dynamic_array(len);
	if (n >= 100 && n <= 999)
	{
		find_word(digits, text, ft_itoa(n / 100, newnum), lenlines);
		n = n % 100;
		find_word(digits, text, ft_itoa(100, newnum), lenlines);
	}
	if (n > 20 && n <= 99)
	{
		find_word(digits, text, ft_itoa((n / 10) * 10, newnum), lenlines);
		n = n % 10;
	}
	if (n > 0)
	{
		newnum = create_dynamic_array(len);
		find_word(digits, text, ft_itoa(n, newnum), lenlines);
	}
	free(newnum);
}

void	big_numbers_in_words(char *num, char **text, \
	char **digits, int lenlines, int n_div)
{
	int		len;
	long	n;

	n = my_atoi(num);
	len = digit_len(num);
	if (n >= 1000)
	{
		n_div = n_div + 1;
		big_numbers_in_words(ft_itoa(n / 1000, num), text, digits, lenlines, n_div);  // con esto llamo a la funcion recursiva
		ft_print_thousands(n_div, digits, text, lenlines);
		n = n % 1000;
	}
	if (n < 1000)
	{
		ft_put_small_nbr(ft_itoa(n, num), text, digits, lenlines);
	}
}

int	main(int argc, char **argv)
{
	char	*array;
	char	*filename;
	char	**digits;
	char	**text;
	int		i;
	int		lenlines;

	i = 0;
	filename = "numbers.dict";
	array = read_file_to_array(filename);
	remove_spaces (array);
	lenlines = count_char (array, '\n') - 1;
	digits = split_digits(array);
	text = split_text(array);
	
	if (argc < 2)
		ft_putstr("Error! Please input arguments.\n");		
	else
		big_numbers_in_words(argv[1], text, digits, lenlines, 0);

	i = 0;

	free(array);
	while (i <  lenlines)
	{
		free(digits[i]);
		free(text[i]);
		i++;
	}
	free(digits);
	return (0);
}
