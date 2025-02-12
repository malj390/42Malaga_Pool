/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:43:38 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/12 14:12:30 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && i == 0)
		{
			str[i] = str[i] - dif;
		}
		if (i > 0 && str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ')
		{
			str[i] = str[i] - dif;
		}
		i++;
	}
	return (str);
}
