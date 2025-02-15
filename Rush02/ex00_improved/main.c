
#include "FUNCTIONS_H"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_dict_entry {
    char *number;
    char *word;
} t_dict_entry;

int	find_word(char **str, char *match, int len)
{
	int i;

	i = 0;
	while(i <= len)
	{
		if (str[i] == match) 
		{
			return (i);
		}
		i++;
	}
	return (1);
}

int main() {

	char	*array;
	char	*filename;
	char	**digits;
	char	**text;
	int		i;
	int c;
	int ifound;

	i = 0;
	
	filename = "numbers.dict";
	array = read_file_to_array(filename);

    remove_spaces(array);
    
    c = count_char(array, '\n') - 1;



    digits = split_digits(array);
	text = split_text(array);

	while( i < c)
	{
		ft_putstr(digits[i]);
		ft_putchar(' ');
		ft_putstr(text[i]);
		ft_putchar('\n');
		i++;
	}

	/*
	Aqui estoy intentando probar si la funcion find_word funciona (no lo hace)
	arreglar y seguir por aqui.
	*/
	ifound = find_word(digits, "0", c);
	ft_putnbr(ifound);
	//ft_putstr(digits[ifound]);

	i = 0;
	free(array);

	while( i <  c) // esto tendría que ser para el tamaño de lineas del diccionario !!
	{

		free(digits[i]);
		free(text[i]);
		i++;
	}
	free(digits);

    return 0;
}
