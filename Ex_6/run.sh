# Compile the test file and the implementation file
gcc -o max_slope_dyn_range_test max_slope_dyn_range_test.c max_slope_dyn_range.c -Wall -Wextra -std=c99

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running tests..."
    echo "----------------------------------------"
    # Run the compiled test executable
    ./max_slope_dyn_range_test
else
    echo "Compilation failed. Please check your code for errors."
fi