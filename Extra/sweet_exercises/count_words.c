#include <stdio.h>

void count_words(char *sentence)
{
    int i = 0, word_count = 0, in_word = 0;

    while (sentence[i])
    {
        if (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n')
        {
            if (in_word == 0)  // Found the start of a word
            {
                word_count++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0; // Reset when we find a space or separator
        }
        i++;
    }

    printf("%d\n", word_count);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s \"sentence\"\n", argv[0]);
        return 1;
    }

    count_words(argv[1]);
    return 0;
}

