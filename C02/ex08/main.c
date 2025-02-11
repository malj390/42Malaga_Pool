/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:11:15 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/11 11:42:01 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strlowcase(char *str);

int main(void)
{
    char str[] = "ESTA FRASE ESTABA EN MAYUSCULA";
    char *res;

    printf("Before: %s\n", str);
    res = ft_strlowcase(str);
    printf("After: %s\n", res);
    return (0);
}

