#include <stdio.h>

void print_array(int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, high + 1);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    void quicksort(int *array, int low, int high);

    quicksort(array, 0, size - 1);
}

void quicksort(int *array, int low, int high)
{
    if (low < high) {
        int pivot = hoare_partition(array, low, high);
        quicksort(array, low, pivot);
        quicksort(array, pivot + 1, high);
    }
}
