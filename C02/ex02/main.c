/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:25:09 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/10 20:44:10 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	int	result1 = 0;
	int	result2 = 0;
	int	result3 = 0;
	char	str_good[] = "Abcdefg";
	char	str_bad[] = "Ab?c&defg";
	char	str_bad2[] = "";

	result1 = ft_str_is_alpha(str_good);
	result2 = ft_str_is_alpha(str_bad);
	result3 = ft_str_is_alpha(str_bad2);
	printf("%s has symbols? %d\n", str_good, result1);
	printf("%s has symbols? %d\n", str_bad, result2);
	printf("%s has symbols? %d", str_bad2, result3);
	return (0);
}
