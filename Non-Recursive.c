#include <stdio.h>

int maxSubArray(int arr[], int n) {
    int max_sum = arr[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += arr[k];
            }
            if (s > max_sum) {
                max_sum = s;
            }
        }
    }
    return max_sum;
}

int main() {
    //first array
    int arr[] = {2, -4, 1, 9, -6, 7, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("first array element : {2, -4, 1, 9, -6, 7, -3} \n");
    printf("largest sum :%d\n\n", maxSubArray(arr, n));
    //scond array
    int arr2[] = {2,-4,1,9,-6,7,-3};
    int n = sizeof(arr2) / sizeof(arr2[0]);
    printf("first array element : {2,-4,1,9,-6,7,-3} \n");
    printf("largest sum :%d\n\n", maxSubArray(arr2, n));
    return 0;
}