/*
Author: ErikMak
Task:

����������� ����� ��� �������� �������� �� ������ �� ����������. ������ ����������� ������ ������ ��������� �� ������ 0,50 �.�., ������ ����� ����� ������ �� ������, � ����� ��������� ���������. � ����� ������ ���� ����� ���������� ����� � ��������� ������� �� ����� �� ������.
�������� ������ ����� �����, ���������� � � ������� ������. ������ ����� ������ ��������� � ���� ��� ������:
	- �����, ����������� ����� �� ������;
	- �����, ����������� ����������������� ��������;
	- �����, ������������ ���������� � ���������� ���������� ����� � ��������� �������.
��������� ������ ���������� ������������ ������ �� ������� "1" ��� ����, ����� ������������ ������������ ������������, � ������� "2", ����� ������������ ����������������� ��������. ������� ������� "3" ������ �������� � ������ ������� �������� ���������� ����� � ������� � ���������� ���������. 

*/
#include <iostream>
#include <windows.h>

class PaymentPoint {
    private:
        const double price = 0.5;
        int passedCars;
        double money;
    public:
        PaymentPoint() {
            passedCars = 0; money = 0;
        }
        void payFare() {
            money += price;
            passedCars++;
            std::cout << "����� " << price << " �� ������ ������� ��������!" << std::endl;
        }
        void skipFare() {
            passedCars++;
            std::cout << "�� �� �������� ������!" << std::endl;
        }
        void getInfo() {
            std::cout << "===================================" << std::endl;
            std::cout << "���������� �� ������ ������" << std::endl;
            std::cout << "����� ��������: " << passedCars << std::endl;
            std::cout << "�������� �������: " << money << std::endl;
        }
};

int getMenuItem() {
    int key;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &key) != 1 || key < 1 || key > 3) {
        std::cout << "������ �����!" << std::endl;
        scanf("%s", s);
    }
    return key;
}

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    PaymentPoint toll;
    
    std::cout << "������ ����� ������" << std::endl;
    std::cout << "1. ������������ ������ �������" << std::endl;
    std::cout << "2. ������������ ����������������� ��������" << std::endl;
    std::cout << "3. ������� �������� ���������� � ���-�� ����� � �������" << std::endl;
    std::cout << "===================================" << std::endl;


    int key;
    do {
        key = getMenuItem();

        switch(key) {
            case 1:
                toll.payFare();
                break;
            case 2:
                toll.skipFare();
                break;
        }
    } while (key!=3);
    toll.getInfo();
}