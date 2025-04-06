# Compile the test file and the implementation file
gcc -o extract_maximum_tests extract_maximum_tests.c extract_maximum.c

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running tests..."
    echo "----------------------------------------"
    # Run the compiled tests
    ./extract_maximum_tests
else
    echo "Compilation failed. Please check your code for errors."
fi