/**
 * @brief Sequential Merge Sort in C.
 *
 * @merge_sort.c
 * @author Willy Villalobos
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Random int list generator.
 *
 * @param buffer
 * @param size
 */
void number_list_gen(int *buffer, int size)
{
    // Generate srand seed.
    unsigned int seed = 42;
    srand(seed);

    // Fill list buffer with random values between 1 and 100.
    for (int i = 0; i < size; i++)
        buffer[i] = rand() % 100 + 1;
}

/**
 * @brief Print input array. Values are separated by space.
 *
 * @param array
 * @param size
 */
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**
 * @brief Merge arrays.
 *
 * @param array
 * @param lower_idx
 * @param mid_idx
 * @param higher_idx
 */
void merge(int array[], int lower_idx, int mid_idx, int higher_idx)
{
    // Create temp arrays for merge.
    int n1 = mid_idx - lower_idx + 1;
    int n2 = higher_idx - mid_idx;

    // Initialize indexes for temp arrays.
    int i, j, k;

    int lower_array[n1], higher_array[n2];

    // Copy data to new temp arrays.
    for (i = 0; i < n1; i++)
        lower_array[i] = array[lower_idx + i];
    for (j = 0; j < n2; j++)
        higher_array[j] = array[mid_idx + j + 1];

    // Merge temp arrays into original input array.
    i = 0;
    j = 0;
    k = lower_idx;

    while (i < n1 && j < n2)
    {
        if (lower_array[i] <= higher_array[j])
        {
            array[k] = lower_array[i];
            i++;
        }
        else
        {
            array[k] = higher_array[j];
            j++;
        }
        k++;
    }

    // Copy remaining items of lower_idx[] and higher_idx[] if any.
    while (i < n1)
    {
        array[k] = lower_array[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = higher_array[j];
        j++;
        k++;
    }
}

/**
 * @brief Merge sort algorithm. Requires
 *
 * @param array
 * @param lower_idx
 * @param higher_idx
 */
void merge_sort(int array[], int lower_idx, int higher_idx)
{
    if (lower_idx < higher_idx)
    {
        int mid_idx = lower_idx + (higher_idx - lower_idx) / 2;
        merge_sort(array, lower_idx, mid_idx);
        merge_sort(array, mid_idx + 1, higher_idx);
        merge(array, lower_idx, mid_idx, higher_idx);
    }
}

// Main
/**
 * @brief
 *
 * @return int
 */
int main()
{
    int list_to_sort[64] = {0};
    number_list_gen(list_to_sort, 64);
    printf("This is the generated array:\n");
    print_array(list_to_sort, 64);

    merge_sort(list_to_sort, 0, 64 - 1);

    printf("This is the sorted array:\n");
    print_array(list_to_sort, 64);

    return 0;
}