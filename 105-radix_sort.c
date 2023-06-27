#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the maximum element in an array
 *
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: The maximum element in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Performs the counting sort algorithm on a single digit
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 * @exp: The current exponent/digit to consider
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i > 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              LSD Radix sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort(array, size, exp);
}
