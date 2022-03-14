/*
Author: ErikMak
Task:

��������� �����
�) ����������� ����
�) ���������� ������ �����
�) ���������� ������� �����������
�) �������������� ��������� ������ � ������� �������
�) �������������� ��������� ������ � ������ �������
�) ������������ ��������� �����
�) ����� ����� � ����
�) ������ �� ������������� �����(������ ���� � ���������, ��������, "�++ ������������� ���������� �������������� ����")

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <cstdlib>

int getMenuItem() {
    int key;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &key) != 1 || key < 1 || key > 6) {
        std::cout << "������ �����!"<< std::endl;
        scanf("%s", s);
    }
    return key;
}

std::string toUpperCase(std::string str){
	for(int i = 0; i < str.length(); i++) {
	    if(str[i]<='z' && str[i]>='a')
		    str[i]+='A'-'a';
		else if(str[i]<='�' && str[i]>='�')
		    str[i]+='�'-'�';
	}
	return str;
}

std::string toLowerCase(std::string str) {
	for(int i = 0; i < str.length(); i++) {
	    if(str[i]>'A' && str[i]<'Z') 
			str[i]+='z'-'Z';
	    else if(str[i]>'�' && str[i]<'�') 
			str[i]+='�'-'�';
	}
	return str;
}

void uploadToFile(const std::string str) {
	std::ofstream fin("output.txt", std::ios::in | std::ios::trunc);
	fin << str << std::endl;
	fin.close();
}

std::string uploadFromFile(char path[256], std::string str) {
	std::ifstream fout(path, std::ios::out);
	if (!fout.good()) {
		std::cout << "\n������ ������ �����!";
        std::cout << "\n===================================" << std::endl;
	} else {
		std::getline(fout, str);
		return str;
	}
}

std::string toJoinString(std::string str) {
	std::string buff;
	std::cout << "\n������� ������, ������� ����������� ��������:" << std::endl;
	std::cin.clear();
	std::cin.sync();
    std::getline(std::cin, buff);
	return str + buff;
} 

int main() {
	SetConsoleCP(1251);
   	SetConsoleOutputCP(1251);
   	system("color 70");
   	
	std::string str;
	std::string buff;
	
	std::cout << "������ ��� ��������������:" << std::endl;
	std::getline(std::cin, str);
	
	std::cout << "\n===================================" << std::endl;
    std::cout << "1. �������������� � ������� �������" << std::endl;
    std::cout << "2. �������������� � ������ �������" << std::endl;
    std::cout << "3. ������������ �� �������" << std::endl;
    std::cout << "4. ����� ����� � ����" << std::endl;
    std::cout << "5. ��������� � �����" << std::endl;
    std::cout << "6. �����" << std::endl;

	int key;
	do {
		key = getMenuItem();
		
		switch (key) {
            case 1:
            	str = toUpperCase(str);
            	std::cout << "\n������ ����� ���������:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
                break;
            case 2:
            	str = toLowerCase(str);
            	std::cout << "\n������ ����� ���������:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
                break;
            case 3:
            	str = toJoinString(str);
            	std::cout << "\n������ ����� ���������:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
                break;
            case 4:
            	uploadToFile(str);
            	std::cout << "\n������ ���� ������� �������� � ���� output.txt";
            	std::cout << "\n===================================" << std::endl;
            	system("output.txt");
                break;
            case 5:
            	std::cout << "\n������� ���� � �����, ������� ���������� ���������:" << std::endl;
            	char path[256];
            	std::cin.clear();
				std::cin.sync();
    			std::cin.getline(path, 256);
            	str = uploadFromFile(path, str);
            	std::cout << "\n������, ����������� � �����:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
            	break;
        }
	} while (key != 6);
}
