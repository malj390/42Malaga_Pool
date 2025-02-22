/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:11:15 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 11:34:27 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strupcase(char *str);

int main(void)
{
    char str[] = "esta frase estaba en minuscula"; // Cadena mutable
    char *res;
    char *res2;

    printf("Before: %s\n", str);
    res = ft_strupcase(str);
    printf("After: %s\n", res);
    res2 = ft_strupcase(str);
    printf("After (oficial): %s\n", res2);
    return (0);
}

