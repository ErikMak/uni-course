/*
Author: ErikMak
Task:

Напишите программу, которая проверяет, является ли введённая строка изограммой.
Строка состоит из множества латинских букв в разном регистре, пробелов и знаков препинания.
Причём в изограмме пробелы или знаки препинания могут повторяться.

*/
#include <iostream>
#include <string>

bool isIsogram (std::string str) {
    std::string buff;

    for(unsigned int i = 0; i < str.length(); i++) {
        if(isalpha(str[i])) {
            buff += tolower(str[i]);
        }
    }

    for(unsigned int i = 0; i < buff.length(); i++) {
        for(unsigned int j = i+1; j < buff.length(); j++) {
            if (buff[i] == buff[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string text_input;
    std::cout << "Insert string:" << std::endl;
    std::getline(std::cin, text_input);

    if(isIsogram(text_input)) {
        std::cout << "This is isogram string" << std::endl;
    } else {
        std::cout << "This isn't isogram string" << std::endl;
    }
}