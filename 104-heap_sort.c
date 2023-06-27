#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Performs the sift-down operation on a heap
 *
 * @array: Pointer to the array representing the heap
 * @size: Size of the heap
 * @root: Index of the root node
 * @end: Index of the last element in the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t max_child, child;
    int temp;

    while ((child = 2 * root + 1) <= end)
    {
        max_child = child;

        if (child + 1 <= end && array[child] < array[child + 1])
            max_child = child + 1;

        if (array[root] < array[max_child])
        {
            temp = array[root];
            array[root] = array[max_child];
            array[max_child] = temp;
            print_array(array, size);
        }
        else
        {
            break;
        }

        root = max_child;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             the sift-down Heap sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int temp;
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        sift_down(array, size, i - 1, size - 1);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        print_array(array, size);
        sift_down(array, size, 0, i - 1);
    }
}
