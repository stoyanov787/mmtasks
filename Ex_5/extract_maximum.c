/*
    This program defines a function to find the maximum value in an array and copy a specified number of elements around that maximum into a separate array.
    It includes error handling for invalid inputs and prints the results to the console.
*/
#include <stdio.h>
#include <stdint.h>
#include "extract_maximum.h"
#define ELEMENTS_TO_COPY 5
#define START_INDEX_POSITION_FROM_MAX 2

int find_maximum_index(uint16_t *arr, int count)
{
    // Check for valid input
    if (arr == NULL || count <= 0)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    // Find the index of the maximum value
    uint16_t max_index = 0;
    for (uint16_t index = 1; index < count; index++)
    {
        if (arr[index] > arr[max_index])
        {
            max_index = index;
        }
    }
    return max_index;
}

int determine_start_index(int max_index, int count)
{
    // Check for valid input
    if (max_index < 0 || count <= 0)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    // Determine the start index for copying
    int start = max_index - START_INDEX_POSITION_FROM_MAX;

    // Adjust start if it's outside the array bounds
    if (start < 0)
    {
        start = 0;
    }

    // Ensure we don't go beyond array bounds
    if (start + ELEMENTS_TO_COPY > count)
    {
        start = count - ELEMENTS_TO_COPY;
    }

    return start;
}

void extract_maximum(uint16_t *in_arr, uint16_t *out_arr, int count)
{
    // Check for valid input
    if (in_arr == NULL || out_arr == NULL || count < ELEMENTS_TO_COPY)
    {
        printf("Invalid arguments\n");
        return;
    }

    // Find the index of the maximum value
    int max_index = find_maximum_index(in_arr, count);
    if (max_index < 0)
    {
        printf("Error finding maximum index\n");
        return;
    }

    printf("Maximum value: %d\n", in_arr[max_index]);
    printf("Maximum index: %d\n", max_index);

    // Determine the start index for copying
    int start = determine_start_index(max_index, count);
    if (start < 0)
    {
        printf("Error determining start index\n");
        return;
    }

    printf("Start index for copying: %d\n", start);

    // Copy the elements to the output array
    for (uint16_t index = 0; index < ELEMENTS_TO_COPY; index++)
    {
        out_arr[index] = in_arr[start + index];
    }

    printf("The elements are copied from index %d to %d\n", start, start + ELEMENTS_TO_COPY - 1);
    printf("The elements are copied to the output array\n");
}
