/*
Author: ErikMak
Task:

����������� �� switch()
�)���������� 4-� ��������: "+", "-", "*", "/"
�)���������� ����� 2-� ��������� � 1-�� ���������
�)��������� ���������� ������(������� �� ����, �������� �� ������ ������ � �.�.)

*/

#include <iostream>
#include <windows.h>

char getOperator() {
	char operation;
	
	printf("������� ��������� ��������:\n�������� => +\n��������� => -\n��������� => *\n������� => /\n\n");	
	char s[100];
    scanf("%s", s);
    while (sscanf(s, "%c", &operation) != 1 || ((int)operation != 45 && (int)operation != 43 && (int)operation != 47 && (int)operation != 42)) {
        std::cout << "������ �����!" << std::endl;
        scanf("%s", s);
    }
    return operation;
}

float getNumericType() {
    float number;
    char s[100];
    scanf("%s", s);

    while (!sscanf(s, "%f", &number)) {
        std::cout << "������ �����! ������� ��� ���:" << std::endl;
        scanf("%s", s);
    }
    return number;
}

int main() {
	SetConsoleCP(1251);
   	SetConsoleOutputCP(1251);
   	system("color 70");
	
	float a, b;

	char operation = getOperator();
	switch (operation){
    	case '-':
		    printf("������ �����: ");
			a = getNumericType();			
			printf("������ �����: ");
			b = getNumericType();

        	std::cout << a <<" - " << b << " = " << a - b <<'\n';
        	break;
    	case '+':
        	printf("������ �����: ");
			a = getNumericType();			
			printf("������ �����: ");
			b = getNumericType();

        	std::cout << a <<" + " << b << " = " << a + b <<'\n';
        	break;
    	case '*':
        	printf("������ �����: ");
			a = getNumericType();			
			printf("������ �����: ");
			b = getNumericType();

        	std::cout << a << " * " << b << " = " << a * b <<'\n';
        	break;
    	case '/':
    		printf("������ �����: ");
			a = getNumericType();			
			printf("������ �����: ");
			b = getNumericType();
			while(b == 0){
				std::cout << "�������� �� ����� ���� ������ 0. ������� ��� ���:" << std::endl;
				b = getNumericType();
			}
			std::cout << a << " / " << b << " = " << a / b <<'\n';
        	break;
    }
}
