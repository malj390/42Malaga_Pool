#ifndef FT_FUNCTIONS_H //verifica si la macro FT_FUNCTIONS_H no ha sido aún definida
# define FT_FUNCTIONS_H // define la macro FT_FUNCTIONS_H(previene que el archivo se incluya más de una vez)

/*incluir solo aquí los headers necesarios
INCLUIR EN TODOS LOS ARCHIVOS (a parte de el makefile) EL HEADER DE 42 (en esto tambien)*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*incluir aquí las definiciones de funcíon*/
char	*create_dynamic_array(int size);  //example
int	get_bytes_size(char *str); //example

/*QUITAR LOS COMMENTARIOS*/

#endif
