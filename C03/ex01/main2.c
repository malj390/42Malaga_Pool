#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

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
    unsigned int n1 = 5; // Comparar 5 caracteres
    unsigned int n2 = 3; // Comparar 3 caracteres
    unsigned int n3 = 0; // Comparar 0 caracteres

    // Ejecutar pruebas
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test1a, test1b, n1, ft_strncmp(test1a, test1b, n1)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test2a, test2b, n1, ft_strncmp(test2a, test2b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test3a, test3b, n2, ft_strncmp(test3a, test3b, n2)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test4a, test4b, n1, ft_strncmp(test4a, test4b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test5a, test5b, n1, ft_strncmp(test5a, test5b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test6a, test6b, n1, ft_strncmp(test6a, test6b, n1)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test7a, test7b, n1, ft_strncmp(test7a, test7b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test1a, test1b, n3, ft_strncmp(test1a, test1b, n3)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test1a, test2b, n3, ft_strncmp(test1a, test2b, n3)); // 0
    
    printf("\n\n\n");
    // Ejecutar pruebas oficiales
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test1a, test1b, n1, ft_strncmp(test1a, test1b, n1)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test2a, test2b, n1, ft_strncmp(test2a, test2b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test3a, test3b, n2, ft_strncmp(test3a, test3b, n2)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test4a, test4b, n1, ft_strncmp(test4a, test4b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test5a, test5b, n1, ft_strncmp(test5a, test5b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test6a, test6b, n1, ft_strncmp(test6a, test6b, n1)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test7a, test7b, n1, ft_strncmp(test7a, test7b, n1)); // <0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test1a, test1b, n3, ft_strncmp(test1a, test1b, n3)); // 0
    printf("Comparando \"%s\" y \"%s\" con n = %d: %d\n", test1a, test2b, n3, ft_strncmp(test1a, test2b, n3)); // 0
    return 0;
}
