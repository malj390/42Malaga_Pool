#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int *array;
    int size;
    int i;

    if (start > end)
        return NULL;

    size = end - start + 1;
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
        return NULL;

    for (i = 0; i < size; i++)
        array[i] = start + i;

    return array;
}

// Test the function
int main()
{
    int start = 3, end = 10;
    int *arr = ft_range(start, end);
    
    if (arr)
    {
        for (int i = 0; i <= (end - start); i++)
            printf("%d ", arr[i]);
        printf("\n");

        free(arr);
    }
    else
    {
        printf("Memory allocation failed or invalid range.\n");
    }

    return 0;
}

