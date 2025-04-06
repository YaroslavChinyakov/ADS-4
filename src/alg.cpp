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
                int leftCount = 0;
                while (left < len && arr[left] == leftVal) {
                    leftCount++;
                    left++;
                }
                
                int rightVal = arr[right];
                int rightCount = 0;
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

        
        int lo = i + 1, hi = len;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        int firstOccurrence = lo;
        
        if (firstOccurrence < len && arr[firstOccurrence] == target) {
            
            lo = firstOccurrence;
            hi = len;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] <= target) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            int lastOccurrence = lo; 
            count += (lastOccurrence - firstOccurrence);
        }
    }
    return count;
}
