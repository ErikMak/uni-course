/*
Author: ErikMak
Task:

Напишите программу, которая вводит с клавиатуры последовательность чисел. 
Длина последовательности тоже задаётся пользователем. 
Затем реализуйте свой любимый алгоритм сортировки для
того, чтобы упорядочить эту последовательность по возрастанию.
Ваша программа не должна ограничивать длину последовательности 
размером используемой структуры данных для её хранения.

*/

#include <iostream>

void merge(int *arr, const size_t first, const size_t last) {
    // Временный массив
    int *buff = new int[20];
    size_t middle = (first + last) / 2;
    // Начало левой и правой части
    size_t l_start = first;
    size_t r_start = middle+1;

    for(size_t i = first; i <= last; i++) {
        if((l_start <= middle) && ((r_start > last) || (arr[l_start] < arr[r_start]))) {
            buff[i] = arr[l_start];
            l_start++; // Сдвигаем границу левой части
        } else {
            buff[i] = arr[r_start];
            r_start++; // Сдвигаем границу правой части
        }
    }

    for(size_t j = first; j <= last; j++) {
        arr[j] = buff[j];
    }
    delete[] buff;
}

void mergeSort(int *arr, const size_t first, const size_t last) {
    if(first < last) {
        mergeSort(arr, first, (first + last)/2); // Сортировка левой части
        mergeSort(arr, (first+last)/2+1, last); // Сортировка правой части
        merge(arr, first, last);
    }
}

int main() {
    size_t n;
    std::cout << "Array size: " << std::endl;
    std::cin >> n;

    int *arr = new int[n];
    for (size_t i = 0; i < n; i++) {
        std::cout << "[" << i << "]: ";
        std::cin >> arr[i];
    }  

    mergeSort(arr, 0, n-1);

    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }  
}