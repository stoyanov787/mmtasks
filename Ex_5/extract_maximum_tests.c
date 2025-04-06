/*
    Tests for the extract_maximum function
    This code includes three test cases to validate the functionality of the extract_maximum function.
    Each test case checks different scenarios, including when the maximum value is at the beginning, middle, or end of the input array.
    The expected output is compared with the actual output to ensure correctness.
*/
#include <stdio.h>
#include <stdint.h>
#include "extract_maximum.h"
#include "extract_maximum_tests.h"
#define ELEMENTS_TO_COPY 5

void print_array(uint16_t *arr, int count)
{
    // Check for valid input
    if (arr == NULL || count <= 0)
    {
        printf("Invalid arguments\n");
        return;
    }

    // Print the array elements
    for (uint16_t index = 0; index < count; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

void check_test(uint16_t *arr, int count, uint16_t *expected_arr)
{
    // Check for valid input
    if (arr == NULL || expected_arr == NULL || count < ELEMENTS_TO_COPY)
    {
        printf("Invalid arguments\n");
        return;
    }

    // Check if the output array matches the expected array
    for (uint16_t index = 0; index < ELEMENTS_TO_COPY; index++)
    {
        if (arr[index] != expected_arr[index])
        {
            printf("Test failed at index %d: expected %d, got %d\n", index, expected_arr[index], arr[index]);
            return;
        }
    }
    printf("Test passed\n");
}

void test1(void)
{
    // Test case 1: The maximum is at the end of the array
    uint16_t in_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 10;
    uint16_t out_arr[ELEMENTS_TO_COPY];

    printf("Test case 1 The maximum is at the end of the array:\n");
    printf("Input array: ");
    print_array(in_arr, count);
    extract_maximum(in_arr, out_arr, count);
    printf("Extracted elements: ");
    print_array(out_arr, ELEMENTS_TO_COPY);

    uint16_t expected_arr[] = {6, 7, 8, 9, 10};
    check_test(out_arr, ELEMENTS_TO_COPY, expected_arr);
}

void test2(void)
{
    // Test case 2: The maximum is at the beginning of the array
    uint16_t in_arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int count = 10;
    uint16_t out_arr[ELEMENTS_TO_COPY];

    printf("Test case 2 The maximum is at the beginning of the array:\n");
    printf("Input array: ");
    print_array(in_arr, count);
    extract_maximum(in_arr, out_arr, count);
    printf("Extracted elements: ");
    print_array(out_arr, ELEMENTS_TO_COPY);

    uint16_t expected_arr[] = {10, 9, 8, 7, 6};
    check_test(out_arr, ELEMENTS_TO_COPY, expected_arr);
}

void test3(void)
{
    // Test case 3: The maximum is in the middle of the array
    uint16_t in_arr[] = {1, 2, 3, 10, 5, 6, 7, 8, 9};
    int count = 9;
    uint16_t out_arr[ELEMENTS_TO_COPY];

    printf("Test case 3 The maximum is in the middle of the array:\n");
    printf("Input array: ");
    print_array(in_arr, count);
    extract_maximum(in_arr, out_arr, count);
    printf("Extracted elements: ");
    print_array(out_arr, ELEMENTS_TO_COPY);

    uint16_t expected_arr[] = {2, 3, 10, 5, 6};
    check_test(out_arr, ELEMENTS_TO_COPY, expected_arr);
}

int main(void)
{
    // Test case 1: The maximum is at the end of the array
    test1();
    printf("\n\n\n------------------------\n\n\n");
    // Test case 2: The maximum is at the beginning of the array
    test2();
    printf("\n\n\n------------------------\n\n\n");
    // Test case 3: The maximum is in the middle of the array
    test3();

    return 0;
}