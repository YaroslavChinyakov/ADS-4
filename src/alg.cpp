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
            int leftVal = arr[left];
            int rightVal = arr[right];

            int leftCount = 0;
            while (left < right && arr[left] == leftVal) {
                ++leftCount;
                ++left;
            }

            int rightCount = 0;
            while (right >= left && arr[right] == rightVal) {
                ++rightCount;
                --right;
            }

            count += leftCount * rightCount;
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
        int complement = value - arr[i];
        if (complement < arr[i]) continue; 

       
        int left = i + 1, right = len - 1;
        int start = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == complement) {
                start = mid;
                right = mid - 1;
            }
            else if (arr[mid] < complement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        
        if (start != -1) {
            int c = 0;
            while (start + c < len && arr[start + c] == complement) {
                ++c;
            }
            count += c;
        }
    }

    return count;
}
