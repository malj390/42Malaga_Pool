/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet_alterning.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:23:57 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/07 13:25:52 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	i;

	i = 'a';
	while (i <= 'z')
	{
		if (i % 2 == 0)
		{
			putchar(i - 32);
		}
		else
		{
			putchar(i);
		}
		i++;
	}
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
