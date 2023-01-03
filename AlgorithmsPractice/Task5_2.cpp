/*
Author: ErikMak
Task:

Переделайте программы из предыдущего задания, чтобы вместо
суммы функция std::accumulate считала произведение элементов.

*/

#include <iostream>
#include <array>
#include <numeric>

//typedef int MyArr[5];
typedef std::array<int, 5>MyArr;

void f(MyArr &a) {
	a[4] = 0;
}

int sum(MyArr a) {
	return std::accumulate(a.begin(), a.end(), 1, [](int x, int y){ return x * y; });
}

int main() {
	MyArr a = { 1,2,3,4,5 };
	std::cout << "Sum1: " << sum(a) << std::endl;
	f(a);
	std::cout << "Sum2: " << sum(a) << std::endl;
}