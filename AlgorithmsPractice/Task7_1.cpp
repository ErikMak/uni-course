/*
Author: ErikMak
Task:

Анаграмма — это слово, полученное из исходного перестановкой букв. 
Напишите программу, которая определяет, какие слова
из списка являются анаграммами заданного слова.
Например, для слова «listen» и списка «enlists», «google», «inlets»,
«banana» программа должна вывести список из одного элемента: «inlets».
Предварительный отсев слов-кандидатов выполняйте с помощью 
вычисления хеш-функции от этих строк.


*/

#include <iostream>
#include <string>
#include <list>
#include <cmath>

int hash(std::string s) {
    int result = 1;
    for (size_t i = 0; i < s.length(); ++i) {
        result *= (s[i] + 31);
    }
    return result;
}

void findAnagram(std::string word, std::list<std::string> list) {
    std::list<std::string> buff;
    int r_hash = hash(word);
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (r_hash == hash(*it)) {
            buff.push_back(*it);
        }
    }
    for (auto it = buff.begin(); it != buff.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::list<std::string> list;
    list.push_back("enlists");
    list.push_back("google");
    list.push_back("inlets");
    list.push_back("banana");

    findAnagram("listen", list);
}