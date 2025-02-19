/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:41:03 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 21:41:07 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_putstr(char *str);

int	main(void)
{
	char *str = "Hello 42 Malaga!";

	ft_putstr(str);
	return (0);
}
