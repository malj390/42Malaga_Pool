/* ************************************************************************** */
/*   ft_putchar.c                                                             */
/*                                                        :::      ::::::::   */
/*   By: aruiz-ca <aruiz-ca@student.42malaga>           :+:      :+:    :+:   */
/*   By: sfedosee <sfefosee@student.42malaga>         +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:52 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/02 17:47:11 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
