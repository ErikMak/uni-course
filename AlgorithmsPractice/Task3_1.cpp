/*
Author: ErikMak
Task:

Перепишите следующую программу, используя std::vector.
Последовательно избавьтесь от следующих конструкций:
• Операторы new[]/delete[] (переменные a и b превратите в
объекты std::vector.
• Переменная m и цикл для вычисления её значения.

*/

#include <iostream>
#include <vector>

void A() {
    int n;
    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int k;
    std::cin >> k;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < k) {
            ++m;
        }
    }
    int* b = new int[m];
    m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < k) {
            b[m++] = a[i];
        }
    }
    delete[] a;
    for (int i = 0; i < m; ++i) {
        std::cout << b[i] << ' ';
    }
    delete[] b;
}

void B() {
    int n;
    std::cout << "Size of first array:";
    std::cin >> n;
    std::vector<int> a;
    std::vector<int> b;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cout << "Element:";
        std::cin >> val;
        a.push_back(val);
    }
    int k;
    std::cout << "K:";
    std::cin >> k;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < k) {
            b.push_back(a[i]);
        }
    }
    std::cout << "Result:";
    for (int i = 0; i < b.size(); ++i) {
        std::cout << b[i] << ' ';
    }
}

int main() {
    B();
}