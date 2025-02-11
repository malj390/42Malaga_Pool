/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:14:15 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/10 20:42:16 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_numeric(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	if (str[0] == '\0')
		res = res * 1;
	while (str[i] != '\0')
	{
		if ((str[i] <= '9' && str[i] >= '0'))
		{
			res = res * 1;
		}
		else
		{
			res = res * 0;
		}

		i++;
	}
	return(res);
}
