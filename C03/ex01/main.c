/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:34:14 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/17 19:19:34 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char s1[] = "ABC";
	char s2[] = "ABF";
	char s3[] = "";
	char s4[] = "ABC1";
	int	n;
	int r;

	n = 4;

	r = ft_strncmp(s1, s1, n);
	printf("s1 s1 %s and %s is %d with n = %d\n", s1, s1, r, n);
	r = ft_strncmp(s1, s2, n);
	printf("s1 s2 %s and %s is %d with n = %d\n", s1, s2, r, n);
	r = ft_strncmp(s1, s4, n);
	printf("s1 s4 %s and %s is %d with n = %d\n", s1, s4, r, n);
	r = ft_strncmp(s3, s3, n);
	printf("s3 s3 %s and %s is %d with n = %d\n", s3, s3, r, n);
	r = strncmp(s1, s2, n);
	printf("oficial s1 s2 %s and %s is %d with n = %d\n", s1, s2, r, n);
	return (0); 
}
