/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoribio <jtoribio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:09:25 by adiaz-sa          #+#    #+#             */
/*   Updated: 2025/02/16 23:08:09 by jtoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>
#include <stdlib.h>

int	digit_len(char *str)
{
	int	i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		i++;
	}
	return (i);
}

// function that copies the src string to dest and null terminates the result
char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split_digits(char *str)
{
	char	**big_ptr;
	char	*small_ptr;
	int		i;
	int		dig_len;
	int		j;

	i = 0;
	j = 0;
	big_ptr = (char **)malloc(count_lines(str) * 8);
	while (str[i] != 0)
	{
		if (i == 0 || str[i - 1] == '\n')
		{
			dig_len = digit_len(&str[i]);
			small_ptr = create_dynamic_array(dig_len + 1);
			big_ptr[j] = small_ptr;
			ft_strncpy(small_ptr, &str[i], dig_len);
			i = i + dig_len - 1;
			j++;
		}
		i++;
	}
	return (big_ptr);
}

char	**split_text(char *str)//Demasiadas variables
{
	int		text_len;
	int		i;
	int		j;
	char	*small_ptr;
	char	**big_ptr;

	i = 0;
	j = 0;
	big_ptr = (char **) malloc(count_lines(str) * 8);
	while (str[i] != '\0')
	{
		if (i > 0 && str[i - 1] == ':')
		{
			text_len = count_text(&str[i]);
			small_ptr = create_dynamic_array(text_len + 1);
			big_ptr[j] = small_ptr;
			ft_strncpy(small_ptr, &str[i], text_len);
			i = i + text_len - 1;
			j++;
		}
		i++;
	}
	return (big_ptr);
}
