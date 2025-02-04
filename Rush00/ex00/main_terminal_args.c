/* ************************************************************************** */
/*   main.c                                                                   */
/*                                                        :::      ::::::::   */
/*   main_terminal_args.c                               :+:      :+:    :+:   */
/*   By: sfedosee <sfefosee@student.42malaga>         +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:52 by mlermo-j          #+#    #+#             */
/*   Updated: 2025/02/04 20:16:45 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> // From here comes the original atoi, not used

int	rush(int x, int y);

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
	if (argc == 3)
	{
		int a = my_atoi(argv[1]);
		int b = my_atoi(argv[2]);
		rush(a, b);
	}
	return (0);
}

