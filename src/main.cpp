#include <iostream>
#include "dynamic_array.h"
#include "bubble_sort.h"

void input_validator(int& input) {
    std::cin >> input;
    while (std::cin.fail()){
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');   
            std::cout << "некорректный ввод" << '\n';
            std::cin >> input;
        }
}

void input_validator(std::size_t& input) {
    std::cin >> input;
    while (std::cin.fail()){
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');   
            std::cout << "некорректный ввод" << '\n';
            std::cin >> input;
        }
}

int main() {

    int in;
    int* array = nullptr;
    std::size_t size;

    while(true) {
        std::cout << '\n';
        std::cout << "меню команд:" << '\n';
        std::cout << "0 - выход" << '\n';
        std::cout << "1 - создать массив" << '\n';
        std::cout << "2 - напечатать массив" << '\n';
        std::cout << "3 - вставить элемента в массив" << '\n';
        std::cout << "4 - удалить элемент" << '\n';
        std::cout << "5 - изменить размер" << '\n';
        std::cout << "6 - удаление дубликатов" << '\n';
        std::cout << "7 - сортировка + поиск элемента в отсоритрованном массиве" << '\n';
        std::cout << '\n';

        std::cout << "введите команду: ";
        input_validator(in);



        if(in == 0) {
            if(array != nullptr) {
                dyn::array_destroy(array);
            }
            break;
        }
        
        switch (in) 
        {
            case(1):
                std::cout <<  "Кол-во элементов в массиве: ";
                input_validator(size);
                
                if(array != nullptr) {
                    dyn::array_destroy(array);
                }
                array = dyn::array_create(size);
                
                if(!array) {
                    std::cout << "Ошибка выделения памяти" << '\n';
                    break;
                } else {
                    std::cout << "Создан массив размера " << size << '\n';
                }
                std::cout << "Введите " << size << " элементов, чтобы заполнить массив" << '\n';
                for(int i = 0; i < size; ++i) {
                    int value;
                    std::cout << "Элемент " << i << ": ";
                    input_validator(value);
                    array[i] = value;
                }
                break;
            case(2): {
                if(array == nullptr) {
                    std::cout << "Сначала создайте массив" << '\n';
                    break;
                }
                bbs::print_array(array, size);
                break;
            }
            case(3): {
                if(array == nullptr) {
                    std::cout << "Сначала создайте массив" << '\n';
                    break;
                }
                std::size_t pos;
                int val;
                std::cout << "Индекс: ";
                input_validator(pos);
                std::cout << "Значение: ";
                input_validator(val);
                array = dyn::array_insert(array, size, pos, val);
                break;
            }
            case(4): {
                if(array == nullptr) {
                    std::cout << "Сначала создайте массив" << '\n';
                    break;
                }
                std::size_t pos;
                std::cout << "индекс удаляемого элемента: ";
                input_validator(pos);
                array = dyn::array_remove(array, size, pos);
                break;
            }
            case(5): {
                if(array == nullptr) {
                    std::cout << "Сначала создайте массив" << '\n';
                    break;
                }
                std::size_t new_size;
                std::cout << "новый размер массива: ";
                input_validator(new_size);
                array = dyn::array_resize(array, size, new_size);
                size = new_size;
                break;
            }

            case(6): {
                if(array == nullptr) {
                    std::cout << "Сначала создайте массив" << '\n';
                    break;
                }
                size = bbs::array_unique(array, size);
                break;
            }

            case(7): {
                if(array == nullptr) {
                    std::cout << "Сначала создайте массив" << '\n';
                    break;
                }
                int target;
                std::cout << "значение элемента для поиска: ";
                input_validator(target);
                bbs::bubble_sort(array, size);
                std::cout << "Индекс элемента в отсортированном массиве: " << bbs::binary_search(array, size, target) << '\n';
                break;
            }
            default: {
                std::cout << "некорректный ввод, ознакомьтесь с меню" << '\n';
                break;
            }
        }
    }
    return 0;
}

