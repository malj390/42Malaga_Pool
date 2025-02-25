#include <stdio.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    // Skip leading whitespaces
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;

    // Handle optional sign
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    // Convert digits to integer
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main()
{
    // Test cases
    printf("%d\n", ft_atoi("42"));            // Output: 42
    printf("%d\n", ft_atoi("   1234"));       // Output: 1234
    printf("%d\n", ft_atoi("-42"));           // Output: -42
    printf("%d\n", ft_atoi("+56"));           // Output: 56
    printf("%d\n", ft_atoi("  -789 "));       // Output: -789
    printf("%d\n", ft_atoi("0034"));          // Output: 34
    printf("%d\n", ft_atoi("+-123"));         // Output: 0 (invalid input)
    printf("%d\n", ft_atoi("abc42"));         // Output: 0 (non-numeric start)
    printf("%d\n", ft_atoi("42abc123"));      // Output: 42 (stops at first non-digit)
    printf("%d\n", ft_atoi("2147483647"));    // Output: 2147483647 (INT_MAX)
    printf("%d\n", ft_atoi("-2147483648"));   // Output: -2147483648 (INT_MIN)

    return 0;
}

