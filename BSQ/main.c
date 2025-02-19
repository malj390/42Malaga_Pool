/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:59:28 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 17:01:00 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char **argv)
{
	char	*content;
	int		i;

	if (argc < 2)
	{
		content = read_stdin();
		if (!content || solver(content) < 0)
			ft_putstr("Error\n");
		free(content);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		content = read_file(argv[i]);
		if (!content || solver(content) < 0)
			ft_putstr("Error\n");
		free(content);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
