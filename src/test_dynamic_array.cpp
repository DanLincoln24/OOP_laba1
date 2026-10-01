#include <gtest/gtest.h>
#include "dynamic_array.h"

TEST(DynamicArrayTest, CreateValidPointer) {
    int* arr = dyn::array_create(5);
    ASSERT_NE(arr, nullptr);
    dyn::array_destroy(arr);
}

TEST(DynamicArrayTest, InsertElement) {
    std::size_t size = 3;
    int* arr = dyn::array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    
    arr = dyn::array_insert(arr, size, 1, 99);
    
    EXPECT_EQ(size, 4);
    EXPECT_EQ(arr[1], 99);
    EXPECT_EQ(arr[2], 20);
    
    dyn::array_destroy(arr);
}

TEST(DynamicArrayTest, RemoveElement) {
    std::size_t size = 3;
    int* arr = dyn::array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    
    arr = dyn::array_remove(arr, size, 1);
    
    EXPECT_EQ(size, 2);
    EXPECT_EQ(arr[1], 30);   
    
    dyn::array_destroy(arr);
}

TEST(DynamicArrayTest, ResizeArray) {
    std::size_t size = 2;
    int* arr = dyn::array_create(size);
    arr[0] = 5; arr[1] = 5;
    
    arr = dyn::array_resize(arr, size, 10);
    
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
    
    dyn::array_destroy(arr);
}