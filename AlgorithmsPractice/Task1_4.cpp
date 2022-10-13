/*
Author: ErikMak
Task:

На входе в программу поступает строка из цифр и число n.
Программа должна вывести все непрерывные подстроки исходной
строки длины n.
Например, для строки 49142 и n = 3 вывод будет таким: 491,
914, 142

*/

#include <iostream>
#include <string>

void printSubstrings(std::string str, int n) {
    std::string buff = "";
    int size = str.length();
    int shift = 0;

    if(n > size || n < 1) {
        throw "error";
    }

    while(shift < (size-n)+1) {
        buff = "";
        for (int i = 0 + shift; i < (n + shift); i++) {
            buff += str[i];
        } 
        std::cout << buff << std::endl;
        shift++;
    }
}


int main() {
    std::string text_input;
    int n;

    std::cout << "Input string:" << std::endl;
	std::getline(std::cin, text_input);
	std::cout << "N:" << std::endl;
	std::cin >> n;

    try {
        printSubstrings(text_input, n);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}