/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlero-j@student.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:18:58 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 11:02:04 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	*str_good;
	char	*str_bad;
	char	*str_good2;
	int	rg;
	int	rb;
	int	rb2;

	str_good = "Hahsgdjeg56485647&&y9";
	str_bad = "Los caracteres chinos 大 y la ñññññ no son printables";
	str_good2 = "";

	rg = ft_str_is_printable(str_good);
	rb = ft_str_is_printable(str_bad);
	rb2 = ft_str_is_printable(str_good2);
	printf("Is %s printable? %d\n", str_good, rg);
	printf("Is %s printable? %d\n", str_bad, rb);
	printf("Is %s printable? %d", str_good2, rb2);
	return (0);
}
