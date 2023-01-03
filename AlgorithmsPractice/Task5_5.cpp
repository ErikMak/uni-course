/*
Author: ErikMak
Task:

Ещё раз доработайте предыдущую программу. Пусть она запрашивает несколько чисел,
которые нужно поискать в массиве. Для каждого нужно вывести нашлось оно или нет.

*/

#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>

int binarySearch(std::vector<int>& arr, int left, int right, const int key) {
	if (right >= left) {
		int middle = left + (right - left) / 2;

		if (arr[middle] == key) {
			return middle;
		}

		if (arr[middle] > key) {
			return binarySearch(arr, left, middle - 1, key);
		}

		return binarySearch(arr, middle + 1, right, key);
	}

	return -1;
}

int main() {
	std::vector<int> arr;
	size_t n;
	int val;
	std::cout << "Array size: "; std::cin >> n;

	for (size_t i = 0; i < n; i++) {
		std::cout << "[" << i << "]: ";
		std::cin >> val;
		arr.push_back(val);
	}

	std::sort(arr.begin(), arr.end(), [](int x, int y) { return x < y; });
	for (size_t i = 0; i < n; i++) {
		std::cout << arr[i] << " | ";
	}
	std::cout << std::endl;

	int m;
	std::cout << "Numbers amount: "; std::cin >> m;
	int* numbers = new int[m];
	for (int i = 0; i < m; i++) {
		std::cout << "Number: "; std::cin >> numbers[i];
	}
	std::cout << "=====" << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < m; i++) {
		int index = binarySearch(arr, 0, n - 1, numbers[i]);
		if (index >= 0) {
			std::cout << "Index of found val: " << index << std::endl;
		}
		else {
			std::cout << "Number not found!" << std::endl;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "=====" << std::endl;
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::duration<double>>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time: " << elapsed_ms.count() << std::endl;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < m; i++) {
		if (std::binary_search(arr.begin(), arr.end(), numbers[i])) {
			std::cout << "Found val: " << numbers[i] << std::endl;
		}
		else {
			std::cout << "Number not found!" << std::endl;
		}
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "=====" << std::endl;
	elapsed_ms = std::chrono::duration_cast<std::chrono::duration<double>>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time: " << elapsed_ms.count() << std::endl;
}