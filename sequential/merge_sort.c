/*
SP-2136
Sequential Merge Sort in C
Author: Willy Villalobos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Random int list generator.
void number_list_gen(int *buffer, int size)
{
    // Generate srand seed.
    unsigned int seed = 42;
    srand(seed);

    // Fill list buffer with random values between 1 and 100.
    for (int i = 0; i < size; i++)
        buffer[i] = rand() % 100 + 1;
}

// Print input array. Values are separated by space.
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Main
int main()
{
    int unsorted_list[64] = {0};
    number_list_gen(unsorted_list, 64);
    print_array(unsorted_list, 64);

    return 0;
}