#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @array: Pointer to the array
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    printf("Swap: %d, %d\n", array[i], array[j]);
}

/**
 * bitonic_merge - Recursively merges a bitonic sequence in the given direction
 *
 * @array: Pointer to the array to merge
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Merge direction (1 for up, 0 for down)
 */
void bitonic_merge(int *array, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        int i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k] && dir) || (array[i] < array[i + k] && !dir))
                swap(array, i, i + k);
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence in the given direction
 *
 * @array: Pointer to the array to sort
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Sort direction (1 for up, 0 for down)
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);
        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
