#include <gtest/gtest.h>
#include "bubble_sort.h"
#include "dynamic_array.h"

TEST(BubbleSortTest, SortsReversedArray) {
    std::size_t size = 4;
    int* arr = dyn::array_create(size);
    arr[0] = 4; arr[1] = 3; arr[2] = 2; arr[3] = 1;

    bbs::bubble_sort(arr, size);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[3], 4);
    
    dyn::array_destroy(arr);
}

TEST(BubbleSortTest, BinarySearchFound) {
    std::size_t size = 3;
    int* arr = dyn::array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30; 
    int index = bbs::binary_search(arr, size, 20);

    EXPECT_EQ(index, 1);
    
    dyn::array_destroy(arr);
}

TEST(BubbleSortTest, BinarySearchNotFound) {
    std::size_t size = 3;
    int* arr = dyn::array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30; 

    int index = bbs::binary_search(arr, size, 99);

    EXPECT_EQ(index, -1);
    
    dyn::array_destroy(arr);
}

TEST(BubbleSortTest, ArrayUniqueRemovesDuplicates) {
    std::size_t size = 5;
    int* arr = dyn::array_create(size);
    arr[0] = 1; arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 3;

    size = bbs::array_unique(arr, size);

    EXPECT_EQ(size, 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    
    dyn::array_destroy(arr);
}

TEST(BubbleSortTest, ArrayUniqueEmptyArray) {
    std::size_t size = 0;
    int* arr = dyn::array_create(size);

    size = bbs::array_unique(arr, size);

    EXPECT_EQ(size, 0);
    
    dyn::array_destroy(arr);
}