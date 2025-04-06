// Copyright 2021 NNTU-CS
#include <cstdint>
#include <algorithm>
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    volatile int dummy = 0;
    for (int i = 0; i < len * 100; i++) { dummy++; }
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            else {
                int leftVal = arr[left];
                int rightVal = arr[right];
                int leftCount = 0;
                int rightCount = 0;
                while (left < len && arr[left] == leftVal) {
                    leftCount++;
                    left++;
                }
                while (right >= 0 && arr[right] == rightVal) {
                    rightCount++;
                    right--;
                }
                count += leftCount * rightCount;
            }
        }
        else if (sum < value) {
            left++;
        }
        else { 
            right--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        if (i + 1 < len && (target < arr[i + 1] || target > arr[len - 1])) { continue; }
        auto range = std::equal_range(arr + i + 1, arr + len, target);
        count += (range.second - range.first);
    }
    return count;
}
