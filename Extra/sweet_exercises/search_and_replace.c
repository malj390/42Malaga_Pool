#include <stdlib.h>
#include <stdio.h>

void search_and_replace(char *sentence, char *find, char *replace)
{
    int i = 0, j, match;
    
    while (sentence[i])
    {
        match = 1;
        j = 0;
        
        // Check if 'find' matches the substring at position 'i'
        while (find[j])
        {
            if (sentence[i + j] != find[j])
            {
                match = 0;
                break;
            }
            j++;
        }

        // If a match is found, print the replacement and skip 'find' length
        if (match)
        {
            int k = 0;
            while (replace[k])
            {
                printf("%c", replace[k]);
                k++;
            }
            i += j; // Move index forward by length of 'find'
        }
        else
        {
            printf("%c", sentence[i]);
            i++;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <sentence> <word_to_find> <replacement>\n", argv[0]);
        return 1;
    }

    search_and_replace(argv[1], argv[2], argv[3]);
    printf("\n");

    return 0;
}

