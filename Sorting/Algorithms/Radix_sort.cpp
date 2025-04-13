#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum element in the array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Function to perform counting sort based on a specific digit
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0};   // Count array for digits (0-9)

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count array to hold the actual position of digits
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array in a stable manner
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted output array back to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Perform counting sort for each digit (exp = 1, 10, 100, ...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, exp);
}

// Main function to test the Radix Sort
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
