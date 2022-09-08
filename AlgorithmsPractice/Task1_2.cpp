/*
Author: ErikMak
Task:

Боб не очень любит разговаривать, поэтому использует небольшой набор реплик.
Он отвечает <<Sure.>> на любой вопрос, например <<How are you?>>.
Он говорит <<Whoa, chill out!>>, если вы КРИЧИТЕ НА НЕГО (то есть используете одни заглавные буквы).
Он отвечает <<Calm down, I know what I'm doing!>> на вопрос, в котором вы кричите.
Он говорит <<Fine. Be that way!>> если вы обращаетесь к нему, но ничего
не говорите (это значит, что входная строка программы состоит из пробельных символов).
Он говорит <<Whatever.>> во всех остальных случаях.
Напишите диалоговую программу, которая имитирует разговор с Бобом. На каждую входную строку она
должна выводить такой ответ, какой давал бы Боб в такой же ситуации. Входные реплики для программы
должны подчиняться правилам пунктуации английского языка.

*/

#include <iostream>
#include <string>

bool isQuestion(std::string str) {
    for(unsigned int i = str.length(); i > 0; i--) {
        if(str[i-1] == '?') {
            return true;
        }
    }
    return false;
}

bool isUppercase(std::string str) {
    for(unsigned int i = 0; i < str.length(); i++) {
        if(!isalpha(str[i])) {
            continue;
        }
        if(str[i] > 'Z' || str[i] < 'A') {
            return false;
        }
    }
    return true;
}

bool isSilence(std::string str) {
    for(unsigned int i = 0; i < str.length(); i++) {
        if(str[i] != ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    std::string text_input;
    std::cout << "Talk with me:" << std::endl;

    while(true) {
        std::getline(std::cin, text_input);

        if(isSilence(text_input)) {
            std::cout << "BOB: Fine. Be that way!" << std::endl;
        } else if (isUppercase(text_input)) {
            if (isQuestion(text_input)) {
                std::cout << "BOB: Calm down, I know what I'm doing!" << std::endl;
            } else {
                std::cout << "BOB: Whoa, chill out!" << std::endl;
            }
        } else if (isQuestion(text_input)) {
            std::cout << "BOB: Sure." << std::endl;
        } else {
            std::cout << "BOB: Whatever." << std::endl;
        }
    }
}