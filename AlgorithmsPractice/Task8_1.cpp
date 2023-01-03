/*
Author: ErikMak
Task:

Перепишите следующую программу, используя std::map.

*/

#include <iostream>
#include <string>
#include <map>

void initialProg() {
    int n;
    std::cout << "Elements amount: ";
    std::cin >> n;
    std::string *word = new std::string[n];
    std::string *def = new std::string[n];  
    for (size_t i = 0; i < n; i++){
		std::cout << "Key: ";
		std::cin >> word[i];
		std::cout << "Value for key: ";
		std::cin >> def[i];
	}
    std::cout << "======" << std::endl;
    std::string s;
    while(std::cin >> s) {
        bool found = false;
        for(int i = 0; !found && i < n; ++i) {
            if(word[i] == s) {
                found = true;
                std::cout << def[i] << '\n';
            }
        }
        if(!found) {
            std::cout << "Not found\n";
        }
    }
    delete[] word;
    delete[] def;
}

int main() {
    int n;
	std::string key, find_value;
	std::map<std::string, std::string> map;
	std::cout << "Elements amount: ";
	std::cin >> n;

	for (size_t i = 0; i < n; i++){
		std::cout << "Key: ";
		std::cin >> key;
		std::cout << "Value for key: ";
		std::cin >> map[key];
	}
	std::cout << "\n\n";
    std::string s;

    std::cout << "Key: ";

    while(std::cin >> s) {
        if(map.find(s)!=map.end()) {   
            std::cout << map[s] << std::endl;
        } else {
            std::cout<< "Not found" << std::endl;
        }
        std::cout << "Key: ";
    }
}