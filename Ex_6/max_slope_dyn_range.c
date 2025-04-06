/*
    This program defines a function to find the maximum value in an array and copy a specified number of elements around that maximum into a separate array.
    It includes error handling for invalid inputs and prints the results to the console.
*/

#include <stdio.h>
#include <stdint.h>
#include "max_slope_dyn_range.h"
#define SLOPE_LENGTH 2
#define FRACTIONAL_BITS_COUNT 8

uint32_t abs_diff(uint32_t number1, uint32_t number2) {
    return (number1 > number2) ? (number1 - number2) : (number2 - number1);
}

int find_max_slope_index(uint32_t* curve, int count) {
    // Check for valid input
    if (curve == NULL || count < SLOPE_LENGTH) {
        printf("Invalid arguments for find_max_slope_index\n");
        return -1;
    }
    
    int max_slope_index = 0;
    uint32_t max_slope = 0;
    
    // Iterate through the array to find the maximum slope
    for (int index = 0; index < count - 1; index++) {
        uint32_t current_slope = abs_diff(curve[index], curve[index+1]);
        
        if (current_slope > max_slope) {
            max_slope = current_slope;
            max_slope_index = index;
        }
    }
    
    return max_slope_index;
}

int update_min_max(uint32_t value, uint32_t* min_value, uint32_t* max_value) {
    // Check for valid input
    if (min_value == NULL || max_value == NULL) {
        printf("Invalid arguments for update_min_max\n");
        return -1;
    }

    if (value < *min_value) {
        *min_value = value;
    }
    if (value > *max_value) {
        *max_value = value;
    }
    return 0;
}

uint16_t max_slope_dyn_range(uint32_t* curve, int count) {
    // Check for valid input
    if (curve == NULL || count < SLOPE_LENGTH) {
        printf("Invalid arguments for max_slope_dyn_range\n");
        return 1;
    }
    
    int max_slope_index = find_max_slope_index(curve, count);
    if (max_slope_index < 0) {
        printf("Error finding max slope index\n");
        return 1;
    }
    
    // Initialize min and max with the values of the two points forming the max slope
    uint32_t min_value = (curve[max_slope_index] < curve[max_slope_index+1]) ? 
                      curve[max_slope_index] : curve[max_slope_index+1];
    uint32_t max_value = (curve[max_slope_index] > curve[max_slope_index+1]) ? 
                      curve[max_slope_index] : curve[max_slope_index+1];
    
    // Check the point before the max slope, if it exists
    if (max_slope_index > 0) {
        if(update_min_max(curve[max_slope_index - 1], &min_value, &max_value) != 0) {
            printf("Error updating min/max before max slope\n");
            return 1;
        }
    }
    
    // Check the point after the max slope, if it exists
    if (max_slope_index + 2 < count) {
        if(update_min_max(curve[max_slope_index + 2], &min_value, &max_value) != 0) {
            printf("Error updating min/max after max slope\n");
            return 1;
        }
    }

    uint32_t ratio;
    if (min_value == 0) {
        // Avoid division by zero
        ratio = UINT16_MAX;
    } else if (max_value >= (UINT32_MAX / (1 << FRACTIONAL_BITS_COUNT))) {
        // Handle potential overflow
        ratio = UINT16_MAX;
    } else {
        // Calculate ratio in fixed-point format
        ratio = (max_value << FRACTIONAL_BITS_COUNT) / min_value;
        
        // Ensure result doesn't exceed uint16_t range
        if (ratio > UINT16_MAX) {
            ratio = UINT16_MAX;
        }
    }
    
    return (uint16_t)ratio;
}