#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max_value = 0, i;
    int *count_array, *output_array;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Allocate memory for the count array */
    count_array = malloc(sizeof(int) * (max_value + 1));
    if (count_array == NULL)
        return;

    /* Initialize the count array with zeros */
    for (i = 0; i <= max_value; i++)
        count_array[i] = 0;

    /* Count the occurrences of each value in the array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the count array */
    print_array(count_array, max_value + 1);

    /* Modify the count array to store the cumulative counts */
    for (i = 1; i <= max_value; i++)
        count_array[i] += count_array[i - 1];

    /* Allocate memory for the output array */
    output_array = malloc(sizeof(int) * size);
    if (output_array == NULL)
    {
        free(count_array);
        return;
    }

    /* Build the output array using the count array */
    for (i = size - 1; i >= 0; i--)
    {
        output_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free memory */
    free(output_array);
    free(count_array);
}
