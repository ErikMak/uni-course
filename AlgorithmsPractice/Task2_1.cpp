/*
Author: ErikMak
Task:

Доработать вторую программу, чтобы получался 
такой же результат, как и в первой. Что нужно изменить, 
чтобы не переделывать функцию sum при изменении 
размера массива

*/

#include <iostream>
#include <array>

//typedef int MyArr[5];
typedef std::array<int, 5>MyArr;

void f(MyArr &a) {
	a[4] = 0;
}

int sum(MyArr a) {
	int r = 0;
	for (std::size_t i = 0; i < a.size(); ++i) {
		r += a[i];
	}
	return r;
}

int main() {
	MyArr a = { 1,2,3,4,5 };
	std::cout << "Sum1: " << sum(a) << std::endl;
	f(a);
	std::cout << "Sum2: " << sum(a) << std::endl;
}