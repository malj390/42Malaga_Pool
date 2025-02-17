#include "functions.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
			ft_putstr("No map was taken. Please provide one as first argument.\n");
	else
	{
		char *array;
		int	len;
		int	i;
	
		array = read_file_to_array(argv[1]);
		len = count(array);


		i = 0;
	while (i <  len)
	{
		ft_putchar(array[i]);
		i++;
	}

	
	free(array);
	}
	return (0);
}