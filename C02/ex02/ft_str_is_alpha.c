/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:25:09 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:09 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	if (str[0] == '\0')
		res = res * 1;
	while (str[i] != '\0')
	{
		if ((str[i] <= 'z' && str[i] >= 'a')
			|| (str[i] <= 'Z' && str[i] >= 'A' ))
		{
			res = res * 1;
		}
		else
		{
			res = res * 0;
		}
		i++;
	}
	return (res);
}
