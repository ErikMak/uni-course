/*
Author: ErikMak
Task:

Напишите программу, которая выводит сколько раз каждое слово 
из входной строки повторяется в ней.
Слова могут состоять из цифр и латинских букв. 
Слова с разным регистром букв считаются одинаковыми. Знаки препинания,
пробелы, переносы строк и символы табуляции нужно игнорировать.


*/

#include <iostream>
#include <string>
#include <map>

std::string toLower(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((char)(str[i] - 'A' + 'a'));
        }
    }
    return str;
}

struct comp {
    bool operator()(const std::string& a, const std::string& b) const {
        return toLower(a) < toLower(b);
    }
};

int main() {
    std::map<std::string, int, comp> map;

    std::string text;
    std::string buff;
    /*
        Тестовый текст
        Lorem ipsum do sit amet, consectetur adipiscing elit, sit do eiusmod elit incididunt ut lorem do dolore elit elit.
        elit - 4
        do - 3
        lorem - 2
        sit - 2
    */
    std::cout << "Input text: ";
    getline(std::cin, text);

    for (size_t i = 0; i <= text.length(); i++) {
        if (text[i] != ' ' && text[i] && ((char)text[i] > 96 && (char)text[i] < 123 || (char)text[i] > 64 && (char)text[i] < 91)) {
            buff += text[i];
        }
        if (text[i] == ' ' || text[i] == '\0') {
            map[buff]++;
            buff = "";
        }
    }
    std::cout << "======\n";
    for (auto pair : map) {
        std::cout << "Word: '" << pair.first << "' met " << pair.second << " times\n";
    }
}