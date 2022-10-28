/*
Author: ErikMak
Task:

Перепишите программу с использованием контейнера std::list
вместо массива. Для вставки значений в список используйте функцию std::list::insert.

*/

#include <iostream>
#include <list>
#include <iterator>

void A() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        for (int j = i; j > 0; --j) {
            a[j] = a[j - 1];
        }
        a[0] = v;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    delete[] a;
}

void B() {
    int n;
    std::cout << "Size:";
    std::cin >> n;
    std::list<int> a;
    for (int i = 0; i < n; ++i) {
        int v;
        std::cout << "Element:";
        std::cin >> v;
        a.insert(a.cbegin(), v);
    }
    std::cout << "Result:";
    for (int val : a) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    std::cout << "Result:";
    copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Result:";
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << ' ';
    }

}

int main() {
    B();
}