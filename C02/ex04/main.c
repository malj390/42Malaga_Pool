/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:18:58 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/10 20:38:11 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	*str_good;
	char	*str_bad;
	char	*str_bad2;
	int	rg;
	int	rb;
	int	rb2;

	str_good = "hola";
	str_bad = "hhhHOLAhhhHH";
	str_bad2 = "";

	rg = ft_str_is_lowercase(str_good);
	rb = ft_str_is_lowercase(str_bad);
	rb2 = ft_str_is_lowercase(str_bad2);
	printf("Is %s lowercase? %d\n", str_good, rg);
	printf("Is %s lowercase? %d\n", str_bad, rb);
	printf("Is %s lowercase? %d", str_bad2, rb2);
	return (0);
}
