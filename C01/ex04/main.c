/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:28 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/05 17:43:02 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
	int a;
	int b;

	a = 5;
	b = 2;
	printf("a / b: %d / %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("Results: a(div), b(mod)= %d, %d\n", a, b);
	return (0);
}
