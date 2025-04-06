// Copyright 2021 NNTU-CS
#include <cstdint>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];
            if (sum == value)
                ++count;
            else if (sum > value)
                break;
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
            ++count;
            int lVal = arr[left];
            int rVal = arr[right];
            while (left < right && arr[left] == lVal)
                ++left;
            while (left < right && arr[right] == rVal)
                --right;
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
        
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int complement = value - arr[i];
        if (std::binary_search(arr + i + 1, arr + len, complement)) {
            ++count;
        }
    }
    return count;
}
