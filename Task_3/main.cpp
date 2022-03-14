/*
Author: ErikMak
Task:

3) ����� �������� ������������ �����
�) ������������ ��������� ����� �������������
�) ����� ����������� �����
�) ���������� ��������� �������

*/
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>

void findFrequentWord(std::vector<std::string> arr) {
	int counter;
	int max = 0;
	std::string buff;
	
	for(int i = 0; i < arr.size(); i++) {
		counter = 0;
		for(int j = 0; j < arr.size(); j++) {
			if (arr[i] == arr[j]){
				counter++;
			}
			if(counter > max){
				max = counter;
				buff = arr[i];
			}
		}
	}
	
	if (max > 1) {
		std::cout << "\n===================================" << std::endl;
		std::cout << "���� ����� ����������� �����: " << buff << ". ��� �������: " << max << std::endl;
	} else {
		std::cout << "\n===================================" << std::endl;
		std::cout << "��� ����� � ������ ����������� � ���������� ��������" << std::endl;
	}
}
void findRightWord(std::vector<std::string> arr) {
	std::string f_word;
	std::cout << "\n������� ���������� �����:" << std::endl;
	std::cin.clear();
	std::cin.sync();
    std::getline(std::cin, f_word);
    
    int counter = 0;
    for(int i = 0; i < arr.size(); i++) {
    	if(arr[i] == f_word) {
    		counter++;
		}
    }
    
    if(!counter){
    	std::cout << "===================================" << std::endl;
    	std::cout << "������ ����� ��� � ������!" << std::endl;
	} else {
		std::cout << "===================================" << std::endl;
		std::cout << "������� ����� �" << f_word << "�. ������� ���������: " << counter << std::endl;
	}
}

int getMenuItem() {
    int key;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &key) != 1 || key < 1 || key > 6) {
        std::cout << "������ �����!" << std::endl;
        scanf("%s", s);
    }
    return key;
}

int main() {
	system("color 70");
	SetConsoleCP(1251);
   	SetConsoleOutputCP(1251);
		
	std::stringstream ss;
	std::string text_input;
	std::cout << "������� ����� ��� ���������� ������:" << std::endl;
	std::getline(std::cin, text_input);
	ss << text_input;
	
	std::vector<std::string> arr;
	std::string word;
	for(int i = 0; ss >> word; i++)
		arr.push_back(word);
	
	std::cout << "\n===================================" << std::endl;
    std::cout << "1. ����� ����� ����� ������������� �����" << std::endl;
    std::cout << "2. ������� ����������� �����?" << std::endl;
    std::cout << "3. �����" << std::endl;

	int key;
	do {
		key = getMenuItem();
		
		switch (key) {
            case 1:
            	findFrequentWord(arr);
                break;
            case 2:
				findRightWord(arr);
                break;
        }
	} while (key != 3);
}
