/**
 * @file omp_merge_sort.c
 * @author Willy Villalobos (gopwivill@gmail.com)
 * @brief Merge Sort algorithm in C using OpenMP pragmas.
 * @version 0.1.0
 * @date 2024-09-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

/**
 * @brief Random integer list generator.
 *
 * @param buffer Pointer to the first element of the array. Array must be preallocated.
 * @param size Size of the array.
 */
void number_list_gen(int *buffer, int size)
{
    // Generate srand seed.
    unsigned int seed = 42;
    srand(seed);

    // Fill list buffer with random values between 1 and 100000.
    for (int i = 0; i < size; i++)
        buffer[i] = rand() % 100000 + 1;
}

/**
 * @brief Print input array. Values are separated by space.
 *
 * @param array Pointer to the array that is going to be printed.
 * @param size Size of the array to be printed.
 */
void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**
 * @brief Merge arrays.
 *
 * @param array Pointer to the array that is going to be merged.
 * @param lower_idx Lower index of the array that is going to be merged.
 * @param mid_idx Middle index of the array that is going to be merged.
 * @param higher_idx higher index of the array that is going to be merged.
 */
void merge(int *array, int lower_idx, int mid_idx, int higher_idx)
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
 * @brief Merge sort algorithm.
 *
 * @param array Integer array that is going to be sorted.
 * @param lower_idx Lowest position of the array that is going to be sorted.
 * @param higher_idx Highest position of the array that is going to be sorted.
 */
void merge_sort(int *array, int lower_idx, int higher_idx)
{
    if (lower_idx < higher_idx)
    {
        int mid_idx = lower_idx + (higher_idx - lower_idx) / 2;
#pragma omp task
        merge_sort(array, lower_idx, mid_idx);
#pragma omp task
        merge_sort(array, mid_idx + 1, higher_idx);
        merge(array, lower_idx, mid_idx, higher_idx);
    }
}

// Main
/**
 * @brief Main program driver. This is where an array is preallocated, filled with random numbers and then sorted.
 *
 * @return Returns 0 if the program was executed successfully.
 */
int main()
{
    // Preallocate buffer with any given size.
    int list_to_sort[64000] = {0};
    number_list_gen(list_to_sort, 64000);
    printf("Skipping array prints.\n");
    // printf("This is the generated array:\n");
    // print_array(list_to_sort, 64000);

    // Measure time using builtin omp function.
    double start_time, stop_time;
    start_time = omp_get_wtime();

    // Pragma parallel merge sort. This could become its own function.
#pragma omp parallel
    {
#pragma omp single
        merge_sort(list_to_sort, 0, 64000 - 1);
    }
    // Stop timer
    stop_time = omp_get_wtime();

    // printf("This is the sorted array:\n");
    // print_array(list_to_sort, 64000);
    printf("\nParallel runtime (S): %g\n", stop_time - start_time);

    return 0;
}