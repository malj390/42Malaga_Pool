/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:52:28 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/05 17:46:26 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	result_div;
	int	result_mod;

	result_div = a / b;
	*div = result_div;
	result_mod = a % b;
	*mod = result_mod;
}
