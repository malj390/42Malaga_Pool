
# Creacion de array dinamico

Aqui se usa malloc para crear un array dinamico, si no hay espacio en memoria muestra el error.

```
int	*create_dynamic_array(int size)
{
	int	*array;

	array = (int*)malloc(size * size * 4);
	if (array == NULL)
	{
		write(1, "Error: No se pudo asignar memoria.\n", 35);
		return NULL;
	}
	return array;
}
```
# Functiones basicas

Esta escribe caracteres

```
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

y esta escribe numeros

```
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
```
# Funcion para mover las filas una respecto a otra

```
void	shift_right(int *row, int size)
{
	int last;
	int i;

	last = row[size - 1];
	i = size - 1;
	while (i > 0)
	{
		row[i] = row[i - 1];
		i--;
	}
	row[0] = last;
}
```
# Funcion que genere el tablero

Primero declaramos las variables

```
void	generate_grid(int *grid, int size, int views[16])
{
	int	first_row[size];
	int	shift_start;
	int	shift_count;
	int	row = 0; 
	int col = 0;

```
Despues rellenamos la primera fila del 1 al 4 empezando por la posicion 0 de la fila

```
	row = 0;
	col = 0;
	while (col < size)
	{
		first_row[col] = (col + 1);
		col++;
	}
```

Aqui empezamos a hacer el shift para cada linea hasta que llegue al tamaño maximo 4

```
	shift_start = 0;
	while (shift_start < size)
	{
		if (views[shift_start] == 4)
			break;
		shift_start++;
	}
```

Aqui shift count nos va contando en que fila estariamos
siempre y cuando sea menos que la posicion en la que se empezo
se hace el shift hacia la derecha

```
	shift_count = 0;
	while (shift_count < shift_start)
	{
		shift_right(first_row, size);
		shift_count++;
	}
```

Aqui empezamos ha rellenar el tablero con cada fila

```
	col = 0;
	while (col < size)
	{
		grid[col] = first_row[col];
		col++;
	}
```

```
	row = 1;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			grid[row * size + col] = grid[(row - 1) * size + (col + 1) % size];
			col++;
		}
		row++;
	}
}
```

# Funcion para imprimir en pantalla el tablero

```
void	print_grid(int *grid, int size) 
{
	int	i;
	int	v;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			v = grid[i * size + j];
			ft_putnbr(v);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
```

# Cambio de caracteres a integros 

```
int my_atoi(char *p)
{
	int k;

	k = 0;
	while (*p) {
		k = k * 10 + (*p) - '0';
		p++;
	}
	return k;
}
```

# Tomando comandos desde argumentos STR en terminal

```
void store_args(int *clues, char **argv, int size) {
	int i;

	i = 0;
	while (i < size) 
    {
		clues[i] = my_atoi(argv[i + 1]);
		i++;
	}
}
```

# MAIN 

```
int main(int argc, char **argv) {
	int size;

	size = 4;
	if (argc != 17) 
    {
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
	return (0);
}

```
