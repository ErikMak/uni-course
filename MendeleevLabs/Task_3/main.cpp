/*
Author: ErikMak
Task:

3) Поиск наиболее встречаемого слова
а) Произвольный введенный текст пользователем
б) Поиск подходящего слова
в) Реализация отдельной функции

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
		std::cout << "Чаще всего встречалось слово: " << buff << ". Его частота: " << max << std::endl;
	} else {
		std::cout << "\n===================================" << std::endl;
		std::cout << "Все слова в тексте встретились с одинаковой частотой" << std::endl;
	}
}
void findRightWord(std::vector<std::string> arr) {
	std::string f_word;
	std::cout << "\nВведите подходящее слово:" << std::endl;
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
    	std::cout << "Такого слова нет в тексте!" << std::endl;
	} else {
		std::cout << "===================================" << std::endl;
		std::cout << "Найдено слово «" << f_word << "». Частота появления: " << counter << std::endl;
	}
}

int getMenuItem() {
    int key;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &key) != 1 || key < 1 || key > 6) {
        std::cout << "Ошибка ввода!" << std::endl;
        scanf("%s", s);
    }
    return key;
}

int main() {
	system("color 70");
	SetConsoleCP(CP_UTF8);
   	SetConsoleOutputCP(CP_UTF8);
		
	std::stringstream ss;
	std::string text_input;
	std::cout << "Введите текст для дальнейшей работы:" << std::endl;
	std::getline(std::cin, text_input);
	ss << text_input;
	
	std::vector<std::string> arr;
	std::string word;
	for(int i = 0; ss >> word; i++)
		arr.push_back(word);
	
	std::cout << "\n===================================" << std::endl;
    std::cout << "1. Найти самое часто встречающиеся слово" << std::endl;
    std::cout << "2. Сколько встретилось слово?" << std::endl;
    std::cout << "3. Выйти" << std::endl;

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
