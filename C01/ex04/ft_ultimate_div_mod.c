/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:22:04 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/05 17:47:01 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	result_div;
	int	result_mod;

	result_div = *a / *b;
	result_mod = *a % *b;
	*a = result_div;
	*b = result_mod;
}
