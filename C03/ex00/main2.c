#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int main() {
    // Casos de prueba
    char *test1a = "hello";
    char *test1b = "hello"; // Iguales
    char *test2a = "hello";
    char *test2b = "world"; // Diferentes
    char *test3a = "abc";
    char *test3b = "ab";    // Diferente en longitud
    char *test4a = "abc";
    char *test4b = "abcd";  // Diferente en longitud
    char *test5a = "abcdef";
    char *test5b = "abcdeg"; // Diferente en el último carácter
    char *test6a = "";
    char *test6b = "";      // Cadenas vacías
    char *test7a = "";
    char *test7b = "abc";   // Cadena vacía vs cadena no vacía

    // Ejecutar pruebas
    printf("Comparando \"%s\" y \"%s\": %d\n", test1a, test1b, ft_strcmp(test1a, test1b)); // 0
    printf("Comparando \"%s\" y \"%s\": %d\n", test2a, test2b, ft_strcmp(test2a, test2b)); // <0
    printf("Comparando \"%s\" y \"%s\": %d\n", test3a, test3b, ft_strcmp(test3a, test3b)); // >0
    printf("Comparando \"%s\" y \"%s\": %d\n", test4a, test4b, ft_strcmp(test4a, test4b)); // <0
    printf("Comparando \"%s\" y \"%s\": %d\n", test5a, test5b, ft_strcmp(test5a, test5b)); // <0
    printf("Comparando \"%s\" y \"%s\": %d\n", test6a, test6b, ft_strcmp(test6a, test6b)); // 0
    printf("Comparando \"%s\" y \"%s\": %d\n", test7a, test7b, ft_strcmp(test7a, test7b)); // <0
    
    printf("\n\n\n");
    // Ejecutar pruebas oficiales
    printf("Comparando \"%s\" y \"%s\": %d\n", test1a, test1b, strcmp(test1a, test1b)); // 0
    printf("Comparando \"%s\" y \"%s\": %d\n", test2a, test2b, strcmp(test2a, test2b)); // <0
    printf("Comparando \"%s\" y \"%s\": %d\n", test3a, test3b, strcmp(test3a, test3b)); // >0
    printf("Comparando \"%s\" y \"%s\": %d\n", test4a, test4b, strcmp(test4a, test4b)); // <0
    printf("Comparando \"%s\" y \"%s\": %d\n", test5a, test5b, strcmp(test5a, test5b)); // <0
    printf("Comparando \"%s\" y \"%s\": %d\n", test6a, test6b, strcmp(test6a, test6b)); // 0
    printf("Comparando \"%s\" y \"%s\": %d\n", test7a, test7b, strcmp(test7a, test7b)); // <0

    return 0;
}
