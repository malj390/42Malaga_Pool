/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:34:14 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/12 17:11:38 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char s1[] = "ABCDE";
	char s2[] = "ABD";
	int r;
	int	n;

	n = 2;
	printf("s1: %s\n", s1); 
	printf("s2: %s\n", s2); 
	printf("n: %d\n", n); 
	r = ft_strncmp(s1, s2, n);	
	printf("Src len: %d", r); 
}
