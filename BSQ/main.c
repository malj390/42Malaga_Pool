/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: ergomez- <ergomez-@student.42malaga.com>     +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:59:28 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/20 10:43:25 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char **argv)
{
	char	*content;
	int		i;
	
	if (argv[0][6] != 'e')
	{
		ft_putstr("Error, the input is not valid.");
		return (0);
	}

	if (argc < 2)
	{
		content = read_stdin();
		if (!content || solver(content) < 0)
			ft_putstr("Error, the input is not valid.");
		free(content);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		content = read_file(argv[i]);
		if (!content || solver(content) < 0)
			ft_putstr("Error, the input is not valid.");
		free(content);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
