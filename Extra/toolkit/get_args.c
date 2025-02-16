/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:40:24 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/14 11:49:34 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
			ft_putstr("Less than 1 argument was taken, please provide one.\n");
	else
	{
		ft_putstr("First argument is argv[0] with value = ");	
		ft_putstr(argv[0]);
		ft_putstr("\n");	
		ft_putstr("Second argument is argv[1] with value = ");	
		ft_putstr(argv[1]);
		ft_putstr("\n");	
	}	
	return (0);
}

