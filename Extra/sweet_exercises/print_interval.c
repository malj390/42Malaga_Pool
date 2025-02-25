#include <stdio.h>

void replace_positions(char *str)
{
    int i = 0;

    while (str[i])
    {
        if ((i + 1) % 15 == 0) // Multiple of both 3 and 5
            str[i] = '8';
        else if ((i + 1) % 3 == 0) // Multiple of 3
            str[i] = '5';
        else if ((i + 1) % 5 == 0) // Multiple of 5
            str[i] = '3';

        i++;
    }

    printf("%s\n", str);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s \"your_string\"\n", argv[0]);
        return 1;
    }

    replace_positions(argv[1]);
    return 0;
}

