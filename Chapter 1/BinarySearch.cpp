#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

// Function template for performing binary search on a vector of any type
// T: Type of the elements in the vector (e.g., int, float, std::string)
// Parameters:
//   arr - Reference to a vector of type T
//   Target - The element to search for in the vector
// Returns:
//   The index of Target in arr if found, otherwise -1
template <typename T>
int binarySearch(std::vector<T> &arr, T Target) {
    int low = 0;                     // Initialize the lower bound of the search range
    int high = arr.size() - 1;        // Initialize the upper bound of the search range
    int mid = (low + high) / 2;       // Calculate the initial mid-point of the range

    // Loop continues as long as the search range is valid
    while (low <= high) {
        mid = (high + low) / 2;       // Recalculate mid-point at each iteration

        // Check if the mid-point element is the target
        if (arr[mid] == Target) {
            return mid;               // Target found, return the index
        }
        
        // If target is smaller than mid-point element, adjust the search range
        if (arr[mid] > Target) {
            high = mid - 1;           // Move the upper bound to the left of mid
        } else {
            low = mid + 1;            // Move the lower bound to the right of mid
        }
    }

    // Target not found in the array
    return -1;
}

// Overload of the output stream operator for printing vectors
// This template allows printing vectors of any type using std::cout
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& arr) {
    for (const auto &i : arr) {
        os << i << " ";               // Output each element followed by a space
    }
    return os;                        // Return the output stream
}

int main() {
    // Test cases for binarySearch function

    // Vector of integers
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Target = 5;                   // Target element to search in arr

    // Vector of floats
    std::vector<float> arr2 = {1.2, 3.7, 5.5, 99.7, 10.5, 0.5};
    float Target2 = 10.5;             // Target element to search in arr2

    // Vector of strings
    std::vector<std::string> arr3 = {
        "ahmed", "ali", "mohamed", "omar", "khaled", "nader", "Alaa",
        "salma", "nada", "nour", "noura", "tamer", "fatma", "sara", "sama"
    };
    std::string Target3 = "ali";      // Target element to search in arr3

    // Sorting arr3 to ensure binary search works correctly
    std::sort(arr3.begin(), arr3.end());

    // Output the sorted arr3
    std::cout << "Sorted arr3: " << arr3 << std::endl;

    // Perform binary searches and print the results
    std::cout << "Index of " << Target << " in arr: " << binarySearch(arr, Target) << std::endl;
    std::cout << "Index of " << Target2 << " in arr2: " << binarySearch(arr2, Target2) << std::endl;
    std::cout << "Index of " << Target3 << " in arr3: " << binarySearch(arr3, Target3) << std::endl;

    return 0;
}
