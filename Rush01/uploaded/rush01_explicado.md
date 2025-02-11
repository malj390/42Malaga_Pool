# Creación de un Array Dinámico en C

En este documento explicamos cómo se implementa un tablero dinámico en C, utilizando `malloc` para la asignación de memoria y otras funciones auxiliares para su manipulación.

## Creación de un Array Dinámico

Aquí usamos `malloc` para crear un array dinámico. Si no hay suficiente espacio en memoria, se muestra un error.

```c
#include <stdlib.h>
#include <unistd.h>

int *create_dynamic_array(int size) {
    int *array;
    
    array = (int *)malloc(size * size * sizeof(int));
    if (array == NULL) {
        write(1, "Error: No se pudo asignar memoria.\n", 35);
        return NULL;
    }
    return array;
}
```

## Funciones Básicas

### Función para escribir un carácter

```c
void ft_putchar(char c) {
    write(1, &c, 1);
}
```

### Función para imprimir un número entero

```c
void ft_putnbr(int n) {
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
    ft_putchar(' ');
}
```

## Función para Rotar una Fila hacia la Derecha

Esta función mueve los elementos de una fila del tablero una posición hacia la derecha.

```c
void shift_right(int *row, int size) {
    int last = row[size - 1];
    int i = size - 1;
    
    while (i > 0) {
        row[i] = row[i - 1];
        i--;
    }
    row[0] = last;
}
```

## Generación del Tablero

Esta función genera el tablero a partir de las pistas (`views`).

```c
void generate_grid(int *grid, int size, int views[16]) {
    int first_row[size];
    int shift_start = 0;
    int shift_count = 0;
    int row, col;

    // Rellenar la primera fila con los números 1 a size (4 en este caso)
    for (col = 0; col < size; col++) {
        first_row[col] = col + 1;
    }

    // Determinar cuántos desplazamientos iniciales se deben hacer
    while (shift_start < size) {
        if (views[shift_start] == 4) {
            break;
        }
        shift_start++;
    }

    // Realizar los desplazamientos hacia la derecha
    while (shift_count < shift_start) {
        shift_right(first_row, size);
        shift_count++;
    }

    // Copiar la primera fila al tablero
    for (col = 0; col < size; col++) {
        grid[col] = first_row[col];
    }

    // Rellenar el resto del tablero siguiendo la lógica de rotación
    for (row = 1; row < size; row++) {
        for (col = 0; col < size; col++) {
            grid[row * size + col] = grid[(row - 1) * size + (col + 1) % size];
        }
    }
}
```

## Función para Imprimir el Tablero

Esta función imprime el tablero en la terminal, formateado en filas y columnas.

```c
void print_grid(int *grid, int size) {
    int i, j, v;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            v = grid[i * size + j];
            ft_putnbr(v);
        }
        ft_putchar('\n');
    }
}
```

## Conversión de Cadena a Entero

Esta función convierte una cadena de caracteres numéricos en un número entero.

```c
int my_atoi(char *p) {
    int k = 0;
    
    while (*p) {
        k = k * 10 + (*p - '0');
        p++;
    }
    return k;
}
```

## Almacenar los Argumentos de la Terminal

Esta función almacena los argumentos de la línea de comandos en un array de enteros.

```c
void store_args(int *clues, char **argv, int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        clues[i] = my_atoi(argv[i + 1]);
    }
}
```

## Función Principal (`main`)

```c
int main(int argc, char **argv) {
    int size = 4;
    
    if (argc != 17) {
        write(1, "Error: Expected 16 numbers as arguments.\n", 41);
        return 1;
    }
    
    int *clues = create_dynamic_array(size);
    int *grid = create_dynamic_array(size);
    
    if (clues == NULL || grid == NULL) {
        return 1;
    }
    
    store_args(clues, argv, 16);
    generate_grid(grid, size, clues);
    print_grid(grid, size);
    
    free(clues);
    free(grid);
    
    return 0;
}
```


