#include "dynamic_array.h"

namespace dyn {

int* array_create(std::size_t size) {
    int* data = new int[size]{};
    return data;
}

int* array_resize(int* arr, std::size_t size, std::size_t new_size) {
    int* data = new int[new_size]{};
    std::size_t to_copy = (size < new_size) ? size : new_size;
    for (std::size_t i = 0; i < to_copy; ++i) {
        data[i] = arr[i];
    }
    delete[] arr;
    return data;
}

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value) {
    
    if (pos > size) {
        pos = size;
    }
    int* data = new int[size + 1]{};
    for (std::size_t i = 0; i < pos; ++i) {
        data[i] = arr[i];
    }
    data[pos] = value;
    for (std::size_t i = pos; i < size; ++i) {
        data[i + 1] = arr[i];
    }
    delete[] arr;
    ++size;
    return data;
}

int* array_remove(int* array, std::size_t& size, std::size_t pos) {
    if (size == 0 || pos >= size) {
        return array;
    }
    int* data = new int[size - 1]{};
    for (std::size_t i = 0; i < pos; ++i) {
        data[i] = array[i];
    }
    for (std::size_t i = pos + 1; i < size; ++i) {
        data[i - 1] = array[i];
    }
    delete[] array;
    --size;
    return data;
}

void array_destroy(int* array) {
    delete[] array; 
}

}
