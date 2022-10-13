/*
Author: ErikMak
Task:

При шифровании удаляются все знаки препинания и пробелы,
а буквы приводятся к нижнему регистру.
Затем нормализованный таким образом текст разбивается на
строки. Эти строки можно выстроить в виде прямоугольника.
Полученный текст перестраивается в виде прямоугольника размером
в r строк и c столбцов, причём c ≥ r и c − r ≤ 1.
Закодированное сообщения получается чтением сверху вниз всех
столбцов от левого до правого.

*/

#include <iostream>
#include <string>

// Функция очистки строки
void clearString(std::string& str) {
	std::string buff;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			buff += tolower(str[i]);
		}
	}
	str = buff;
}

// Функция разделения строки по кол-ву символов
void printString(std::string str, int r) {
	int size = str.length();
	std::string result = "";
	std::string buff = "";

	int counter = 0;
	while (counter < size) {
		for (int i = 0; i < r; i++) {
			buff += str[counter];
			counter++;
		}
		result += buff;
		buff = " ";
	}
	std::cout << result << std::endl;
}

std::string encryptString(std::string str, int c) {
	/*
		tmp_c - кол-во столбцов квадрата с учетом добавления
		новых символов в строку

		0123456  	     0123			   01
		abcdehu    => adubceh   =>   adube_ch

		tmp_c = 3	  tmp_c = 2		 tmp_c = 1
	*/
	int tmp_c = c;
	int shift = 0;
	int insert_shift;
	int j = 0;

	// Цикл по кол-ву колонок квадрата
	for(int i = 0; i < c; i++) {
		// Длина строки - длина добавленных символов
		j = (str.length() - 1) - shift;
		// Сдвиг для вставки букв (с учетом длины добавленных символов)
		insert_shift = shift;
		while(j >= 0) {
			if (j % tmp_c == 0) {
				// Буква с индексом j с учетом длины добавленных символов
				char letter = str[j + shift];
				// Добавить в конец
				str.insert(str.begin()+insert_shift, letter);
				// Сдвинуть индексы (длина добавленных символов)
				shift++;
				// Удалить букву с индексом j с учетом добавленных символов
				str.erase(j + shift, 1);
			}
			j--;
		}
		// Добавление пробелов, если длина строчки не равна числу колонок
		while(shift % (c-1) != 0) {
			str.insert(str.begin()+shift, ' ');
			shift++;
		}
		tmp_c--;
	}
	return str;
}

int main() {
	std::string text_input;
	int c, r;
	std::cout << "Input string:" << std::endl;
	std::getline(std::cin, text_input);
	std::cout << "COLUMNS:" << std::endl;
	std::cin >> c;
	std::cout << "ROWS:" << std::endl;
	std::cin >> r;

	try {
		if (c < r || (c - r) > 1) {
			throw "error";
		}
		clearString(text_input);
		text_input = encryptString(text_input, c);
		std::cout << "Result:" << std::endl;
		printString(text_input, r);


		text_input = encryptString(text_input, r);
		std::cout << "Result:" << std::endl;
		clearString(text_input);
		std::cout << text_input << std::endl;
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}