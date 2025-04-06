/*
    Tests for the max_slope_dyn_range function
    This code includes five test cases to validate the functionality of the max_slope_dyn_range function.
    Each test case checks different scenarios, including when the maximum slope is at the beginning, middle, or end of the input array.
    The expected output is compared with the actual output to ensure correctness.
*/
#include <stdio.h>
#include <stdint.h>
#include "max_slope_dyn_range.h"
#include "max_slope_dyn_range_test.h"


void print_array(uint32_t *arr, int count) {
    // Check for valid input
    if (arr == NULL || count <= 0) {
        printf("Invalid arguments for print_array\n");
        return;
    }
    
    // Print the array elements
    for (int index = 0; index < count; index++) {
        printf("%u ", arr[index]);
    }
    printf("\n");
}

void test1(void) {
    // Test case 1: The maximum is at the end of the array
    printf("Test case 1: The maximum is at the end of the array:\n");
    uint32_t curve[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = sizeof(curve) / sizeof(curve[0]);
    
    uint16_t result = max_slope_dyn_range(curve, count);
    printf("The input array is: ");
    print_array(curve, count);
    printf("Max slope dynamic range: %.2f\n", result / 256.0);

    uint16_t expected_result = 768;
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected %u, got %u\n", expected_result, result);
    }
}

void test2(void) {
    // Test case 2: The maximum is at the beginning of the array
    printf("Test case 2: The maximum is at the beginning of the array:\n");
    uint32_t curve[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int count = sizeof(curve) / sizeof(curve[0]);
    
    uint16_t result = max_slope_dyn_range(curve, count);
    printf("The input array is: ");
    print_array(curve, count);
    printf("Max slope dynamic range: %.2f\n", result / 256.0);

    uint16_t expected_result = 320;
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected %u, got %u\n", expected_result, result);
    }
}

void test3(void) {
    // Test case 3: The maximum is in the middle of the array
    printf("Test case 3: The maximum is in the middle of the array:\n");
    uint32_t curve[] = {1, 2, 3, 10, 5, 6, 7, 8, 9, 4};
    int count = sizeof(curve) / sizeof(curve[0]);
    
    uint16_t result = max_slope_dyn_range(curve, count);
    printf("The input array is: ");
    print_array(curve, count);
    printf("Max slope dynamic range: %.2f\n", result / 256.0);

    uint16_t expected_result = 1280;
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected %u, got %u\n", expected_result, result);
    }
}

void test4(void) {
    // Test case 4: Test case with zero value
    printf("Test case 4: Test case with zero value:\n");
    uint32_t curve[] = {0, 10, 5, 7};
    int count = sizeof(curve) / sizeof(curve[0]);
    
    uint16_t result = max_slope_dyn_range(curve, count);
    printf("The input array is: ");
    print_array(curve, count);
    printf("Max slope dynamic range: %.2f\n", result / 256.0);

    uint16_t expected_result = 65535;
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected %u, got %u\n", expected_result, result);
    }
}

void test5(void) {
    // Test case 5: Test case with overflow
    printf("Test case 5: Test case with overflow:\n");
    uint32_t curve[] = {0, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD};
    int count = sizeof(curve) / sizeof(curve[0]);

    uint16_t result = max_slope_dyn_range(curve, count);
    printf("The input array is: ");
    print_array(curve, count);
    printf("Max slope dynamic range: %.2f\n", result / 256.0);

    uint16_t expected_result = 65535;
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected %u, got %u\n", expected_result, result);
    }
}

int main(void) {
    test1();
    printf("\n\n\n------------------------\n\n\n");
    test2();
    printf("\n\n\n------------------------\n\n\n");
    test3();
    printf("\n\n\n------------------------\n\n\n");
    test4();
    printf("\n\n\n------------------------\n\n\n");
    test5();
    
    return 0;
}