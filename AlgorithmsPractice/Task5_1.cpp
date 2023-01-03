/*
Author: ErikMak
Task:

Переделайте функции sum в программах из задания 2.1, 
используя алгоритм std::accumulate. Для этого потребуется подключить
заголовочный файл numeric.

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
	// для суммы элементов из первой половины
	// return std::accumulate(a.begin(), a.begin() + (a.size() / 2), 0);
	return std::accumulate(a.begin(), a.end(), 0);
}

int main() {
	MyArr a = { 1,2,3,4,5 };
	std::cout << "Sum1: " << sum(a) << std::endl;
	f(a);
	std::cout << "Sum2: " << sum(a) << std::endl;
}