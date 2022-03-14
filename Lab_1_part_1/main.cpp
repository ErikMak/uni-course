/*
Author: ErikMak
Task:

Составить программу для перевода числа, представляющего собой запись натурального 
положительного числа в p-системе счисления (2 <= p <= 9) в десятичную систему счисления.

*/

#include <iostream>
#include <cstring>
#include <windows.h>

int raiseToDegree(int number, int x){
    if (x == 0)
        return 1;
    return number * raiseToDegree(number, x-1);
}
int convertToDec(std::string number, int base){
    if(base >= 2 && base <= 9) { // Validation
        int summ = 0;
        int size = number.length();
        for(int i = 0; i < size; i++){
            if (base <= static_cast<int>(number[size-i-1] - '0')) { // Validation
                return 0;
            }
            summ += raiseToDegree(base, i) * static_cast<int>(number[size-i-1] - '0');
        }
        return summ;
    }
    return 0;
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string number;
    int base;
    std::cout << "Ввод натурального положительного числа:" << std::endl;
    std::cin >> number;
    std::cout << "В системе счисления p (2 <= p <= 9):" << std::endl;
    std::cin >> base;

    std::cout << "Результат: " << convertToDec(number, base) << std::endl;
}
