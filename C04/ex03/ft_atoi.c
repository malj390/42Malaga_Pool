/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:11:42 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 22:11:45 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_atoi(char *p)
{
	int	k;
	int	i;
	int	sign;
	int	sign_count;

	k = 0;
	i = 0;
	sign_count = 0;
	while (p[i] == ' ' || p[i] == '\t' || p[i] == '\n')
		i++;
	while (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			sign = -1;
		sign_count++;
		i++;
	}
	if (sign_count > 0 && (p[i] < '0' || p[i] > '9'))
		return (0);
	while (p[i] >= '0' && p[i] <= '9')
	{
		k = k * 10 + (p[i] - '0');
		i++;
	}
	return (k * sign);
}
