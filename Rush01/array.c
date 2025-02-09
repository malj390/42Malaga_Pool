#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Esta funcion escribe los caracteres en pantalla
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

// Esta funcion escribe numeros en pantalla tomando integros como argumento
void    ft_putnbr(int n)
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
    }
}

void print_space() {
    write(1, " ", 1);
}

void print_newline() {
    write(1, "\n", 1);
}

// Función para imprimir el array en formato 2D
void print_array(int* array, int size) {
    int i = 0, j = 0;
    
    while (i < size) {
        j = 0;
        while (j < size) {
            printf("%d ", array[i * size + j]);  // Accedemos al valor usando la fórmula
            j++;
        }
        printf("\n");
        i++;
    }
}

int* create_dynamic_array(int size) {
    return (int*)malloc(size * size * 4);  // 4 bytes por cada int
}

// Función para llenar el array en una localización específica
void set_value_at(int* array, int row, int col, int size, int value) {
    // Calculamos el índice lineal correspondiente en el array 1D
    array[row * size + col] = value;
}

// Función para recorrer una fila
void set_value_at_row_f(int* array, int row, int size, int value) {
    
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

// Función para recorrer una fila
void set_value_at_row_b(int* array, int row, int size, int value) {
    
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

// Función para recorrer una columna
void set_value_at_col_f(int* array, int col, int size, int value) {
    int row = 0;
    int pr = 0;
    
    while (row < size) {
        array[row * size + col] = value + pr;
        row++;
        pr++;
    }
}

void set_value_at_col_b(int* array, int col, int size, int value) {
    int row = size - 1;  // Start from the last row
    int pr = 0;

    while (row >= 0) {  // Loop backwards
        array[row * size + col] = value + pr;
        row--;  // Move upwards
        pr++;
    }
}


// Función para llenar todo el array
void fill_array(int* array, int size, int value) {
    // Llenamos el array con valores
    int i = 0, j = 0;
    while (i < size) {
        j = 0;
        while (j < size) {
            set_value_at(array, i, j, size, value);  // Llenamos el array con valores secuenciales
            j++;
        }
        i++;
    }
}

int main(void) {
    int size = 4;
    int* array = create_dynamic_array(size);  // Crear un array 4x4 dinámico solucion


    if (array == NULL) {
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

    // Liberamos la memoria
    free(array);

    return 0;
}