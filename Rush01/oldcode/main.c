#include "FUNCTIONS_H"

int main(int argc, char **argv) {
    int size = 4;
    //int conflict;
    //int count;

    if (argc != 17) {  // 16 numbers + program name
        printf("Error: Expected 16 numbers as arguments.\n");
        return 1;
    }

    int* rowcol = create_dynamic_array(2);

    int* clues = create_dynamic_array(size);
    if (!clues) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    store_args_in_2Darray(clues, argv, size); 
    //print_array(clues, size);
    //ft_putchar('\n');

    int* array = create_dynamic_array(size);

	fill_array(array, rowcol, 4, 0);

	rowcol[0] = 0;
	rowcol[1] = 0;
	set_value_at(array, rowcol, size, 1);

	rowcol[0] = 0;
	rowcol[1] = 1;
	set_value_at(array, rowcol, size, 2);

	rowcol[0] = 0;
	rowcol[1] = 2;
	set_value_at(array, rowcol, size, 3);

	rowcol[0] = 0;
	rowcol[1] = 3;
	set_value_at(array, rowcol, size, 4);

	rowcol[0] = 1;
	rowcol[1] = 0;
	set_value_at(array, rowcol, size, 2);

	rowcol[0] = 1;
	rowcol[1] = 1;
	set_value_at(array, rowcol, size, 3);

	rowcol[0] = 1;
	rowcol[1] = 2;
	set_value_at(array, rowcol, size, 4);

	rowcol[0] = 1;
	rowcol[1] = 3;
	set_value_at(array, rowcol, size, 1);

	rowcol[0] = 2;
	rowcol[1] = 0;
	set_value_at(array, rowcol, size, 3);

	rowcol[0] = 2;
	rowcol[1] = 1;
	set_value_at(array, rowcol, size, 4);

	rowcol[0] = 2;
	rowcol[1] = 2;
	set_value_at(array, rowcol, size, 1);

	rowcol[0] = 2;
	rowcol[1] = 3;
	set_value_at(array, rowcol, size, 2);

	rowcol[0] = 3;
	rowcol[1] = 0;
	set_value_at(array, rowcol, size, 4);

	rowcol[0] = 3;
	rowcol[1] = 1;
	set_value_at(array, rowcol, size, 1);

	rowcol[0] = 3;
	rowcol[1] = 2;
	set_value_at(array, rowcol, size, 2);

	rowcol[0] = 3;
	rowcol[1] = 3;
	set_value_at(array, rowcol, size, 3);
	
	//set_value_at_row_f(array, 0, size, 1);
	//set_value_at_row_b(array, 0, size, 1);

	//set_value_at_col_f(array, 0, size, 1);
	//set_value_at_col_b(array, 2, size, 1);

	//if (solve(array, clues , size, rowcol))
		//print_array(array, size);
	print_array(array, size);

	//conflict = 9;
	//conflict = is_valid(array, size, rowcol, 2); // 1 No conflicts

	//count = count_visible(array);
	//ft_putnbr(count);

	// Liberamos la memoria
	free(array);
    free(clues);
    return 0;
}