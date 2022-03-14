/*
Author: ErikMak
Task:

��������� ��������� ��� �������� �����, ��������������� ����� ������ ������������ 
�������������� ����� � p-������� ��������� (2 <= p <= 9) � ���������� ������� ���������.

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
    std::cout << "���� ������������ �������������� �����:" << std::endl;
    std::cin >> number;
    std::cout << "� ������� ��������� p (2 <= p <= 9):" << std::endl;
    std::cin >> base;

    std::cout << "���������: " << convertToDec(number, base) << std::endl;
}
