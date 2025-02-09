#include "FUNCTIONS_H"


void	set_value_at(int* array, int* rowcol, int size, int value)
{
	array[rowcol[0] * size + rowcol[1]] = value;
}

void	set_value_at_row_f(int* array, int row, int size, int value)
{
	int col;
	int pr;

	col = 0;
	pr = 0;
	while( col < size)
	{
		array[row * size + col] = value + pr;
		col++;
		pr++;
	}
}

void	set_value_at_row_b(int* array, int row, int size, int value)
{
	int col;
	int pr;

	col = size - 1;
	pr = 0;
	while(col >= 0)
	{
		array[row * size + col] = value + pr;
		col--;
		pr++;
	}
}

void	set_value_at_col_f(int* array, int col, int size, int value)
{
	int row = 0;
	int pr = 0;
    
	while (row < size) 
	{
		array[row * size + col] = value + pr;
		row++;
		pr++;
	}
}

void	set_value_at_col_b(int* array, int col, int size, int value)
{
	int row;
	int pr;

	row = size - 1;
	pr = 0;
	while (row >= 0)
	{  // Loop backwards
		array[row * size + col] = value + pr;
		row--;  // Move upwards
		pr++;
	}
}

void	fill_array(int* array, int* rowcol, int size, int value)
{	
	while (rowcol[0] < size)
	{
		while (rowcol[1] < size)
		{
		set_value_at(array, rowcol, size, value);
		rowcol[1]++;
		}
	rowcol[0]++;
	}
}

int is_valid(int* array, int size, int* rowcol, int value)
{	
	int i;

	i = 0;
    while (i < size )
    {
        if (array[rowcol[0] * size + rowcol[1]] == value)
        {
        	return 0; 
        }
        i++;
    }
    while (i < size )
    {
        if (array[rowcol[0] * size + rowcol[1]] == value)
        {
        	return 0; 
        }
        i++;
    }
    return 1; // No conflicts
}

int count_visible(int *line)
{
    int count = 0, max = 0, i = 0;

    while (i < 4) {
        if (line[i] > max) {
            max = line[i];
            count++;
        }
        i++;
    }
    return count;
}

int check_visibility(int* array, int* clues, int size) {
    int line[size];
    int row;
    int col;

    row = 0;
    // Check column visibility (Top and Bottom clues)
    while (row < size) {
        col = 0;
        while (col < size) {
            line[col] = array[col * size + row];  // Extract column using flat array
            col++;
        }
        if (count_visible(line) != clues[row]) return 0; // Top clue

        col = 0;
        while (col < size) {
            line[col] = array[(size - 1 - col) * size + row];  // Reverse column for Bottom clue
            col++;
        }
        if (count_visible(line) != clues[12 + row]) return 0; // Bottom clue

        row++;
    }

    row = 0; // Reset row for row checks
    // Check row visibility (Left and Right clues)
    while (row < size) {
        col = 0;
        while (col < size) {
            line[col] = array[row * size + col];  // Extract row using flat array
            col++;
        }
        if (count_visible(line) != clues[4 + row]) {
            return 0; // Left clue
        }

        col = 0;
        while (col < size) {
            line[col] = array[row * size + (size - 1 - col)];  // Reverse row for Right clue
            col++;
        }
        if (count_visible(line) != clues[8 + row]) {
            return 0; // Right clue
        }
        row++;
    }

    return 1;
}

int solve(int* array, int* clues , int size, int* rowcol) {
    // If we finished all rows, check visibility and return success if valid
    if (rowcol[0] == size)
    {
    	return check_visibility(array, clues, size);
    }

    // Move to next row if column limit reached
    if (rowcol[1] == size)
    {
    	return solve(array, clues, rowcol[0] + 1, 0);
    }

    int num = 1;
    while (num <= size) 
    {   
        if (is_valid(array, size, rowcol, num)) 
        {  // Check row & col uniqueness
            array[rowcol[0] * size + rowcol[1]] = num;  // Place number

            rowcol[1] = rowcol[1] + 1;
            //if (solve(array, clues, size, rowcol[0], rowcol[1] + 1)) 
            if (solve(array, clues, size, rowcol)) 
            	return 1;  // Recursive call

            array[rowcol[0] * size + rowcol[1]] = 0;  // Backtrack if not valid
        }
        num++;
    }
    return 0;  // No valid placement found
}
