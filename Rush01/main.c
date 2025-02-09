#include "FUNCTIONS_H"

int main(int argc, char **argv) {
    int size = 4;

    if (argc != 17) {  // 16 numbers + program name
        printf("Error: Expected 16 numbers as arguments.\n");
        return 1;
    }

    int* clues = create_dynamic_array(size);
    if (!clues) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    store_args_in_array(clues, argv, size); 
    print_array(clues, size);
    ft_putchar('\n');

    int* array = create_dynamic_array(size);

	if (array == NULL)
		{
			printf("Error: No se pudo asignar memoria.\n");
			return 1;
		}

	fill_array(array, 4, 0);
	//set_value_at(array, 1, 1, size, 9);
	//set_value_at_col_f(array, 0, size, 1);
	set_value_at_row_f(array, 0, size, 1);
	set_value_at_row_b(array, 2, size, 1);
	//set_value_at_col_b(array, 2, size, 1);

	print_array(array, 4); 
	check_number(array, 0, size, 4);

	// Liberamos la memoria
	free(array);
    free(clues);
    return 0;
}