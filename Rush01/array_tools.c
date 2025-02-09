#include "FUNCTIONS_H"


int*	create_dynamic_array(int size)
{
	return (int*)malloc(size * size * 4);  // 4 bytes por cada int
}

void	print_array(int* array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", array[i * size + j]);  // Accedemos al valor usando la fórmula
			j++;
		}
			printf("\n");
			i++;
		}
}

void store_args_in_array(int* array, char **argv, int size)
{
    int c = 1;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            array[row * size + col] = my_atoi(argv[c]);
            c++;
        }
    }
}