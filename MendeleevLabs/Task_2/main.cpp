/*
Author: ErikMak
Task:

Обработка строк
а) Бесконечный Цикл
б) Реализация метода выход
в) Реализация методов функционала
г) Преобразование введенной строки в ВЕРХНИЙ регистр
д) Преобразование введенной строки в НИЖНИЙ регистр
е) Конкатенация введенных строк
ё) Вывод строк в файл
ж) Чтение из произвольного файла(Строка слов с пробелами, например, "С++ компилируемый статически типизированный язык")

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
        std::cout << "Ошибка ввода!"<< std::endl;
        scanf("%s", s);
    }
    return key;
}

std::string toUpperCase(std::string str){
	for(int i = 0; i < str.length(); i++) {
	    if(str[i]<='z' && str[i]>='a')
		    str[i]+='A'-'a';
		else if(str[i]<='я' && str[i]>='а')
		    str[i]+='Я'-'я';
	}
	return str;
}

std::string toLowerCase(std::string str) {
	for(int i = 0; i < str.length(); i++) {
	    if(str[i]>'A' && str[i]<'Z') 
			str[i]+='z'-'Z';
	    else if(str[i]>'А' && str[i]<'Я') 
			str[i]+='я'-'Я';
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
		std::cout << "\nОшибка чтения файла!";
        std::cout << "\n===================================" << std::endl;
	} else {
		std::getline(fout, str);
		return str;
	}
}

std::string toJoinString(std::string str) {
	std::string buff;
	std::cout << "\nВведите строку, которую собираетесь добавить:" << std::endl;
	std::cin.clear();
	std::cin.sync();
    std::getline(std::cin, buff);
	return str + buff;
} 

int main() {
	SetConsoleCP(CP_UTF8);
   	SetConsoleOutputCP(CP_UTF8);
   	system("color 70");
   	
	std::string str;
	std::string buff;
	
	std::cout << "Строка для редактирования:" << std::endl;
	std::getline(std::cin, str);
	
	std::cout << "\n===================================" << std::endl;
    std::cout << "1. Преобразование в верхний регистр" << std::endl;
    std::cout << "2. Преобразование в нижний регистр" << std::endl;
    std::cout << "3. Конкатенация со строкой" << std::endl;
    std::cout << "4. Вывод строк в файл" << std::endl;
    std::cout << "5. Прочитать с файла" << std::endl;
    std::cout << "6. Выйти" << std::endl;

	int key;
	do {
		key = getMenuItem();
		
		switch (key) {
            case 1:
            	str = toUpperCase(str);
            	std::cout << "\nСтрока после изменения:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
                break;
            case 2:
            	str = toLowerCase(str);
            	std::cout << "\nСтрока после изменения:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
                break;
            case 3:
            	str = toJoinString(str);
            	std::cout << "\nСтрока после изменения:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
                break;
            case 4:
            	uploadToFile(str);
            	std::cout << "\nДанные были успешно выведены в файл output.txt";
            	std::cout << "\n===================================" << std::endl;
            	system("output.txt");
                break;
            case 5:
            	std::cout << "\nВведите путь к файлу, который необходимо прочитать:" << std::endl;
            	char path[256];
            	std::cin.clear();
				std::cin.sync();
    			std::cin.getline(path, 256);
            	str = uploadFromFile(path, str);
            	std::cout << "\nСтрока, загруженная с файла:" << std::endl;
    			std::cout << str;
    			std::cout << "\n===================================" << std::endl;
            	break;
        }
	} while (key != 6);
}
