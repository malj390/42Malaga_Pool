#include "functions.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
			ft_putstr("No map was taken. Please provide one as first argument.\n");
	else
	{
		//int	i;
		//int	j;
		t_map map;
		//int	**arrayint;

		map = read_file_to_tmap(argv[1]);
		
		if (map.numberint != map.cols)
			ft_putstr("Your description doesn't match with number of cols\n");
		if (map.numberint != map.rows)
			ft_putstr("Your description doesn't match with number of rows\n");
				
		//print_array_1D(map.arraytrimmed, map.lentrimmed);
		ft_putstr("\n");
		//print_array_2D(map.array_2D, map.rows, map.cols);
		ft_putstr("\n");
		
		//transformer(map.array_2D, map.rows, map.cols, map.obstaclesymbol);
		ft_putstr("\n");
		//arrayint = transformer(map.array_2D, map.rows, map.cols);
		//solver(arrayint, map.rows, map.cols);
		find_largest_square(map.array_2D, map.rows, map.cols);
		ft_putstr("\n");
		//print_array_2D(map.array_2D, map.rows, map.cols);

		






		return (0);
	}
}

