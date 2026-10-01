#include <iostream>
#include "dynamic_array.h"

namespace bbs {

int* bubble_sort(int* arr, std::size_t size) {
    if(size == 0 || !arr) return arr;
    if(size == 1) return arr;
    for(int s = size; s > 1; --s) {
        bool is_sorted = true;
        for(int i = 0; i < s - 1; ++i) {
            if(arr[i] > arr[i+1]) {
                is_sorted = false;
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if(is_sorted) {
            return arr;
        }
    }
    return arr;
}

void print_array(int* arr, std::size_t size) {
    if(size == 0 || !arr) return;
    std::cout << arr[0];
    for(int i = 1; i < size; ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << '\n';
}

int binary_search(int* arr, std::size_t size, int target) {
    if(size == 0 || !arr) return -1;
    int l = 0;
    int r = size - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(target > arr[mid]) {
            l = mid + 1;
        } else if(target < arr[mid]) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

std::size_t array_unique(int* arr, std::size_t size) {
    if(size < 2) {
        return size;
    }
    int write_index = 1;
    for(int j = 1; j < size; ++j) {
        if(arr[j] != arr[write_index - 1]) {
            arr[write_index] = arr[j];
            write_index++;
        }
    }

    return write_index;
}

}