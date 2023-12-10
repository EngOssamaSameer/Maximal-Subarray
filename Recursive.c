#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubArrayHelper(int arr[], int left, int right) {
    // Base case: if the input array has only one element, return it
    if (left == right) {
        return arr[left];
    }
    
    // Find the midpoint of the array
    int mid = (left + right) / 2;
    
    // Recursively find the maximum subarray sum in the left half
    int left_max = maxSubArrayHelper(arr, left, mid);
    
    // Recursively find the maximum subarray sum in the right half
    int right_max = maxSubArrayHelper(arr, mid+1, right);
    
    // Find the maximum subarray sum that crosses the midpoint
    int cross_max = arr[mid];
    int temp_sum = arr[mid];
    for (int i = mid-1; i >= left; i--) {
        temp_sum += arr[i];
        cross_max = max(cross_max, temp_sum);
    }
    
    temp_sum = cross_max;
    for (int i = mid+1; i <= right; i++) {
        temp_sum += arr[i];
        cross_max = max(cross_max, temp_sum);
    }
    
    // Return the maximum of the three cases
    return max(max(left_max, right_max), cross_max);
}

int maxSubArray(int arr[], int n) {
    // Call the recursive helper function with the input array and its bounds
    return maxSubArrayHelper(arr, 0, n-1);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubArray(arr, n);
    printf("The maximum subarray sum is: %d\n", max_sum);
    return 0;
}