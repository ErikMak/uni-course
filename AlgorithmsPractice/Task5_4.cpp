/*
Author: ErikMak
Task:

Замените сортировку из программы для предыдущего задания
на функцию std::sort из стандартной библиотеки. Для этого 
понадобится заголовочный файл algorithm.

*/

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> arr;
    size_t n;
    int val;
    std::cout << "Array size: " << std::endl;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        std::cout << "[" << i << "]: ";
        std::cin >> val;
        arr.push_back(val);
    }  

    std::sort (arr.begin(), arr.end(), [](int x, int y){ return x < y; });

    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }  
}