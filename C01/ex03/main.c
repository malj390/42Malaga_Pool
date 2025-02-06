/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:56:10 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/05 17:20:18 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int	a;
	int	b;
	int	result_div;
	int	result_mod;

	a = 5;
	b = 2;
	result_div = 0;
	result_mod = 0;
	printf("a / b: %d / %d\n", a, b);
	printf("Before (div, mod): %d, %d\n", result_div, result_mod);
	ft_div_mod(a, b, &result_div, &result_mod);
	printf("After (div, mod): %d, %d", result_div, result_mod);
	return (0);
}
