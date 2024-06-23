#include <iostream>

// Function to calculate the sum of even numbers in an array using recursion
int sumEven(int arr[], int size, int index = 0, int sum = 0) {
    // Base case: if the index exceeds the array size, return the sum
    if (index >= size) {
        return sum;
    }

    // Recursive case: check if the current element is even, and add it to the sum
    if (arr[index] % 2 == 0) {
        sum += arr[index];
    }

    // Move on to the next element in the array
    return sumEven(arr, size, index + 1, sum);
}

int main() {
    const int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};

    // Calculate the sum of even numbers in the array using recursion
    int result = sumEven(arr, size);

    std::cout << "Sum of even numbers: " << result << std::endl;

    return 0;
}

