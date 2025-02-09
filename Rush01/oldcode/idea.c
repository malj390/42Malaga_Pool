#include <stdlib.h>
#include <unistd.h>

int* create_dynamic_array(int size) {
    int* array = (int*)malloc(size * size * 4);  // Allocate memory for size x size array
    if (array == NULL) {
        write(1, "Error: No se pudo asignar memoria.\n", 35);
        return NULL;
    }
    return array;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		ft_putchar(' ');
	}
}

// Function to rotate an array to the right
void shift_right(int* row, int size) {
    int last = row[size - 1];
    int i = size - 1;
    while (i > 0) {
        row[i] = row[i - 1];
        i--;
    }
    row[0] = last;
}

// Function to generate a valid grid based on constraints
void generate_grid(int* grid, int size, int views[16]) {
    int first_row[size];
    int row = 0, col = 0;

    // Extract first 4 values (col-up view) to determine shift start
    while (col < size) {
        first_row[col] = (col + 1);
        col++;
    }

    // Find where the '4' appears in the first row
    int shift_start = 0;
    while (shift_start < size) {
        if (views[shift_start] == 4)
            break;
        shift_start++;
    }

    // Apply shifts to align the first row correctly
    int shift_count = 0;
    while (shift_count < shift_start) {
        shift_right(first_row, size);
        shift_count++;
    }

    // Copy the first row into the grid (linearized)
    col = 0;
    while (col < size) {
        grid[col] = first_row[col];
        col++;
    }

    // Fill the remaining rows with shifted versions (linearized)
    row = 1;
    while (row < size) {
        col = 0;
        while (col < size) {
            grid[row * size + col] = grid[(row - 1) * size + (col + 1) % size];
            col++;
        }
        row++;
    }
}

// Function to print the grid
void print_grid(int* grid, int size) {
    int i = 0;
    int v;

    while (i < size) {
        int j = 0;
        while (j < size) {
            v = grid[i * size + j];
            ft_putnbr(v);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int my_atoi(char* p) {
    int k = 0;
    while (*p) {
        k = k * 10 + (*p) - '0';
        p++;
    }
    return k;
}

// Function to store command-line arguments into an array
void store_args(int* clues, char** argv, int size) {
    int i = 0;
    while (i < size) {
        clues[i] = my_atoi(argv[i + 1]);
        i++;
    }
}

int main(int argc, char** argv) {
    int size = 4;
    if (argc != 17) {  // Expecting 16 numbers + program name
        write(1, "Error: Expected 16 numbers as arguments.\n", 41);
        return 1;
    }

    // Dynamic memory allocation for clues and grid
    int* clues = create_dynamic_array(size);
    int* grid = create_dynamic_array(size);

    if (clues == NULL || grid == NULL) {
        return 1;
    }

    // Store command-line arguments into clues array
    store_args(clues, argv, 16);

    // Generate the correct grid
    generate_grid(grid, size, clues);

    // Print the final grid
    print_grid(grid, size);

    // Free allocated memory
    free(clues);
    free(grid);

    return 0;
}
