#include "FUNCTIONS_H"


int*	create_dynamic_array(int size)
{
	int* array;

	array = (int*)malloc(size * size * 4);  // 4 bytes por cada int

	if (array == NULL)
		{
			printf("Error: No se pudo asignar memoria.\n");
			return (NULL);
		}

	return (array);
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

void store_args_in_2Darray(int* clues, char **argv, int size)
{
    int c = 1;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            clues[row * size + col] = my_atoi(argv[c]);
            c++;
        }
    }
}

void store_args_in_1Darray(int* clues, char **argv)
{
    int i = 0;
    
    while (i < 16) {
        clues[i] = my_atoi(argv[i + 1]); // Convert and store clues
        i++;
    }
}
