/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:44:23 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/19 19:48:28 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char s1[] = "ABC";
	char s2[] = "AFC";
	char s3[] = "";
	char s4[] = "ABC";


	printf("s1 s1 %s and %s is %d\n", s1, s1, ft_strcmp(s1, s1));
	printf("s1 s2 %s and %s is %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("s1 s4 %s and %s is %d\n", s1, s4, ft_strcmp(s1, s4));
	printf("s3 s3 %s and %s is %d\n", s3, s3, ft_strcmp(s3, s3));
	printf("oficial s1 s2 %s and %s is %d\n", s1, s2, ft_strcmp(s1, s2));
	return (0);
}

