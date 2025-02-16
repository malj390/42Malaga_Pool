/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:54:37 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 21:09:20 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FUNCTIONS_H"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // esto es solo para el print f

typedef struct s_dict_entry
{
	char	*number;
	char	*word;
}	t_dict_entry;

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

void	find_word(char **digits, char **text, char *match,  int len)
{
	int i;

	i = 0;
	while (i < len) // Corrected condition
	{
		if (ft_strcmp(digits[i], match) == 0) // Use strcmp for string comparison
		{
			ft_putstr(text[i]);
			ft_putstr(" ");
		}
		i++;
	}
	//return (NULL); // Return -1 if not found
}

long int big_numbers_in_words(char *num, char **text,	char **digits, int lenlines)
{
	long	n;
	long	len;
	long	r;
	char 	*newnum;
	char 	*newinc;
	int 	inc;
	int i;

	n = my_atoi(num);
	len = digit_len(num);

	i = 1;
	inc = 1;
	while(i < len)
	{
		inc = inc * 10;
		i++;
	}

	newnum = create_dynamic_array(len);
	newinc = create_dynamic_array(len);
	r = n / inc;
	find_word(digits, text, ft_itoa(r, newnum), lenlines);
	find_word(digits, text, ft_itoa(inc, newinc), lenlines);
	free(newnum);
	free(newinc);
	n = n % inc; 
	return (n); 
}

void ft_putnbr_in_words(char *num, char **text,	char **digits, int lenlines)
{
	long	n;
	long	len;
	long	r;
	int 	inc;
	char	*newnum;

	n = my_atoi(num);
	len = digit_len(num);

	if (n < 0)
	{
		n = -n;
		ft_putstr("minus ");
	}

	while (n > 1000)
	{
		newnum = create_dynamic_array(len);
		n = big_numbers_in_words(ft_itoa(n, newnum), text, digits, lenlines);
		free(newnum);
	}

	if (n >= 100 && n <= 999)
	{	
		inc = 100;
		r = n / inc;
		n = n % inc;  // Get the remainder after hundreds
		
		newnum = create_dynamic_array(len);
		ft_itoa(r, newnum);
		find_word(digits, text, newnum, lenlines); // Print hundreds place
		ft_itoa(inc, newnum);
		find_word(digits, text, newnum, lenlines); // Print "hundred"
		free(newnum);
	}

	if (n > 20 && n <= 99)
	{	
		r = (n / 10) * 10; // Get the tens place (e.g., 90 from 95)
		n = n % 10; // Get the last digit
		
		newnum = create_dynamic_array(len);
	    ft_itoa(r, newnum);
		find_word(digits, text, newnum, lenlines); // Print tens place
		free(newnum);
	}

	if (n > 0) // Ensure the last digit (units) is printed
	{
		newnum = create_dynamic_array(len);
		ft_itoa(n, newnum);
		find_word(digits, text, newnum, lenlines);
		free(newnum);
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
		ft_putnbr_in_words(argv[1], text, digits, lenlines);

	i = 0;

	free(array);
	while (i <  lenlines)//esto tendría que ser para el tamaño de lineas del diccionario !!
	{
		free(digits[i]);
		free(text[i]);
		i++;
	}
	free(digits);
	return (0);
}
