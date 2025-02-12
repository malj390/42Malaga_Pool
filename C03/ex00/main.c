/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:44:23 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/12 12:13:31 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char s1[] = "ABC";
	char s2[] = "ABD";
	char s3[] = "";
	int	r;
	int	r2;
	int	r3;
	int	r4;

	r = ft_strcmp(s1, s1);
	r2 = ft_strcmp(s1, s2);
	r3 = ft_strcmp(s2, s1);
	r4 = ft_strcmp(s3, s3);
	printf("%s and %s is %d\n", s1, s1, r);
	printf("%s and %s is %d\n", s1, s2, r2);
	printf("%s and %s is %d\n", s2, s1, r3);
	printf("%s and %s is %d\n", s3, s3, r4);
	return (0);
}

