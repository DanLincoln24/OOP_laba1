#include <cstddef>

namespace dyn {

int* array_create(std::size_t size);

int* array_resize(int* arr, std::size_t size, std::size_t new_size);

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value);

int* array_remove(int* arr, std::size_t& size, std::size_t pos);

void array_destroy(int* arr);

}


