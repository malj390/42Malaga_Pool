/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:18:35 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 12:38:51 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


char *ft_strcapitalize(char *str);

int	main(void)
{
	char	str[] = "esta es la frase a capitalizar";

	printf("%s\n", str);
	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}

