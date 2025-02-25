#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int *array;
    int size;
    int i = 0;

    if (start > end)
        return NULL;

    size = end - start + 1;
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
        return NULL;

    while (start <= end)
    {
        array[i] = start;
        start++;
        i++;
    }

    return array;
}

// Test the function
int main()
{
    int start = 3, end = 10;
    int *arr = ft_range(start, end);
    
    if (arr)
    {
        int i = 0;
        while (i <= (end - start))
        {
            printf("%d ", arr[i]);
            i++;
        }
        printf("\n");

        free(arr);
    }
    else
    {
        printf("Memory allocation failed or invalid range.\n");
    }

    return 0;
}

