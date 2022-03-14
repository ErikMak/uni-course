/*
Author: ErikMak
Task:

Калькулятор на switch()
а)Реализация 4-х операций: "+", "-", "*", "/"
б)Реализация ввода 2-х операндов и 1-го оператора
в)Обработка допустимых ошибок(Деления на ноль, проверка на пустую строку и т.д.)

*/

#include <iostream>
#include <windows.h>

char getOperator() {
	char operation;
	
	printf("Введите доступное действие:\nсложение => +\nвычитание => -\nумножение => *\nделение => /\n\n");	
	char s[100];
    scanf("%s", s);
    while (sscanf(s, "%c", &operation) != 1 || ((int)operation != 45 && (int)operation != 43 && (int)operation != 47 && (int)operation != 42)) {
        std::cout << "Ошибка ввода!" << std::endl;
        scanf("%s", s);
    }
    return operation;
}

float getNumericType() {
    float number;
    char s[100];
    scanf("%s", s);

    while (!sscanf(s, "%f", &number)) {
        std::cout << "Ошибка ввода! Введите еще раз:" << std::endl;
        scanf("%s", s);
    }
    return number;
}

int main() {
	SetConsoleCP(CP_UTF8);
   	SetConsoleOutputCP(CP_UTF8);
   	system("color 70");
	
	float a, b;

	char operation = getOperator();
	switch (operation){
    	case '-':
		    printf("Первое число: ");
			a = getNumericType();			
			printf("Второе число: ");
			b = getNumericType();

        	std::cout << a <<" - " << b << " = " << a - b <<'\n';
        	break;
    	case '+':
        	printf("Первое число: ");
			a = getNumericType();			
			printf("Второе число: ");
			b = getNumericType();

        	std::cout << a <<" + " << b << " = " << a + b <<'\n';
        	break;
    	case '*':
        	printf("Первое число: ");
			a = getNumericType();			
			printf("Второе число: ");
			b = getNumericType();

        	std::cout << a << " * " << b << " = " << a * b <<'\n';
        	break;
    	case '/':
    		printf("Первое число: ");
			a = getNumericType();			
			printf("Второе число: ");
			b = getNumericType();
			while(b == 0){
				std::cout << "Делитель не может быть равным 0. Введите еще раз:" << std::endl;
				b = getNumericType();
			}
			std::cout << a << " / " << b << " = " << a / b <<'\n';
        	break;
    }
}
