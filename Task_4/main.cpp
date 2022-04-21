/*
Author: ErikMak
Task:

Написать программу, которая последовательно выполняет подаваемые ей на вход арифметические операции 
над числами с помощью стека на базе массива. Обеспечить считывание из потока stdin последовательности 
из чисел и арифметических операций, разделенных пробелом. Если элемент входной последовательности - число,
положить в стек. Если элемент входной последовательности - знак операции, то применить эту операцию над 
двумя верхними элементами стека, а результат положить в стек.

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

class CustomStack {
    protected:
        int *mData;
    private:
        std::size_t sizeOfStack;
    public:
        CustomStack();
        // Добавить новый элемент в стек
        void push(const int val);
        // Удалить из стека последний элемент
        void pop();
        // Вернуть размер стека
        std::size_t size();
        // Проверить отсутствие элементов в стеке
        bool empty();
        // Доступ к верхнему элементу стека
        int top();
        // Расширить массив на n элементов
        void extend(const int n);
        ~CustomStack();
};

CustomStack::CustomStack() {
    sizeOfStack = 0; 
    mData = (int*) malloc(sizeof(int));
}
void CustomStack::push(const int val) {
    mData[sizeOfStack] = val;
    ++sizeOfStack;
    // Выделяем память на следующий элемент
    mData = (int*) realloc(mData, (sizeOfStack+1)*sizeof(int));
}
void CustomStack::pop() {
    // Предварительная проверка на пустой массив
    if (this->empty()) {
        throw "error";
    } else {
        mData = (int*) realloc(mData, sizeOfStack*sizeof(int));
        --sizeOfStack;
    }
}
std::size_t CustomStack::size() {
    return sizeOfStack;
}
bool CustomStack::empty() {
    if(sizeOfStack == 0) 
        return true;
    else 
        return false;
}
int CustomStack::top() {
    // Предварительная проверка на пустой массив
    if (this->empty()) {
        throw "error";
    } else {
        return mData[sizeOfStack-1];
    }
}
void CustomStack::extend(const int n) {
    for(int i=0; i<n; i++)
        ++sizeOfStack;
    mData = (int*) realloc(mData, (sizeOfStack+1)*sizeof(int));
}
CustomStack::~CustomStack() {
    free(mData);
}

// Является ли строка числом
bool isNumeric(const char *str) {
    while(*str)  {
        if (*str == '-' || *str == '*' || *str == '/' || *str == '+') {
            *str++;
            if(*str< '0' || *str > '9') 
                return false; 
        }
        *str++;
    }
    return true;
}

// Преобразование из char* в int
int convertToInt(char *str){
    if(*str == '-') {
        int res = 0;
            for (int i = 1; str[i] != '\0'; ++i)
                res = res*10 + str[i] - '0';
            return -res;
    } else {
        int res = 0;
        for (int i = 0; str[i] != '\0'; ++i)
            res = res*10 + str[i] - '0';
        return res;
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    CustomStack stack;

    const unsigned int str_size = 100;
    char str[str_size];
    std::cin.getline(str, str_size);
    
    char *p_str = strtok(str," ");

    try {
        while (p_str != NULL) {
            if(isNumeric(p_str)) {
                // Положить в стек
                int val = convertToInt(p_str);
                stack.push(val);
            } else {
                // Применить эту операцию над двумя верхними элементами 
                int b = stack.top(); // Получить первый верхний элемент
                stack.pop(); // И сразу убрать его
                int a = stack.top(); // Получить второй верхний элемент
                stack.pop(); // И сразу убрать его
                int result;
                switch(*p_str){
                    case '-': result = a - b; break;
                    case '+': result = a + b; break;
                    case '/': result = a / b; break;
                    case '*': result = a * b; break;
                }
                stack.push(result); // Положить результат в стек
            }
            p_str = strtok (NULL, " ");
        }
        if(stack.size() > 1) { // Проверка на размер стека > 1
            throw "error";
        } else {
            // Вывести результат (число в стеке)
            std::cout << stack.top() << std::endl;
        }
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}