/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:23:14 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/08 10:32:34 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int my_atoi(char *p) {
  int k = 0;
  while (*p) {
    k = k*10 + (*p) - '0';
    p++;
  }
  return k;
}

int	main(int argc, char **argv)
{
	if (argc == 16)
	{
		int a1 = my_atoi(argv[1]);
		int a2 = my_atoi(argv[2]);
		int a3 = my_atoi(argv[3]);
		int a4 = my_atoi(argv[4]);
		int a5 = my_atoi(argv[5]);
		int a6 = my_atoi(argv[6]);
		int a7 = my_atoi(argv[7]);
		int a8 = my_atoi(argv[8]);
		int a9 = my_atoi(argv[9]);
		int a10 = my_atoi(argv[10]);
		int a11 = my_atoi(argv[11]);
		int a12 = my_atoi(argv[12]);
		int a13 = my_atoi(argv[13]);
		int a14 = my_atoi(argv[14]);
		int a15 = my_atoi(argv[15]);
		int a16 = my_atoi(argv[16]);
		//rush(a, b);
	}
	return (0);
}
