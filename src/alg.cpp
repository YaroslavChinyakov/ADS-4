// Copyright 2021 NNTU-CS
#include <cstdint>
#include <algorithm>


int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                ++count;
            }
            else if (sum > value) {
                break;
            }
        }
    }
    return count;
}


int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += (n * (n - 1)) / 2;
                break;
            }
            else {
                int lCount = 1;
                int rCount = 1;
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    ++lCount;
                    ++left;
                }
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    ++rCount;
                    --right;
                }
                count += lCount * rCount;
                ++left;
                --right;
            }
        }
        else if (sum < value) {
            ++left;
        }
        else {
            --right;
        }
    }
    return count;
}


int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        if (target < arr[i]) continue;

        
        int left = i + 1;
        int right = len - 1;
        int first = -1, last = -1;

        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                if (arr[mid] == target) first = mid;
                right = mid - 1;
            }
        }

        if (first == -1) continue; 

        
        left = first;
        right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
            }
            else {
                if (arr[mid] == target) last = mid;
                left = mid + 1;
            }
        }

        if (last != -1)
            count += (last - first + 1);
    }

    return count;
}
