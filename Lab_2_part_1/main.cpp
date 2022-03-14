/*
Author: ErikMak
Task:

Представьте пункт для взимания платежей за проезд по автостраде. Каждая проезжающая машина должна заплатить за проезд 0,50 у.е., однако часть машин платит за проезд, а часть проезжает бесплатно. В кассе ведётся учёт числа проехавших машин и суммарная выручка от платы за проезд.
Создайте модель такой кассы, реализовав её с помощью класса. Данный класс должен содержать в себе три метода:
	- метод, имитирующий плату за проезд;
	- метод, имитирующий недобросовестного водителя;
	- метод, отображающий информацию о количестве проехавших машин и суммарной выручке.
Программа должна предложить пользователю нажать на клавишу "1" для того, чтобы сымитировать заплатившего автолюбителя, и клавишу "2", чтобы сымитировать недобросовестного водителя. Нажатие клавиши "3" должно привести к выдаче текущих значений количества машин и выручки и завершению программы. 

*/
#include <iostream>
#include <windows.h>

class PaymentPoint {
    private:
        const double price = 0.5;
        int passedCars;
        double money;
    public:
        PaymentPoint() {
            passedCars = 0; money = 0;
        }
        void payFare() {
            money += price;
            passedCars++;
            std::cout << "Плата " << price << " за проезд успешно оплачена!" << std::endl;
        }
        void skipFare() {
            passedCars++;
            std::cout << "Вы не оплатили проезд!" << std::endl;
        }
        void getInfo() {
            std::cout << "===================================" << std::endl;
            std::cout << "Информация по пункту оплаты" << std::endl;
            std::cout << "Машин проехало: " << passedCars << std::endl;
            std::cout << "Итоговая выручка: " << money << std::endl;
        }
};

int getMenuItem() {
    int key;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &key) != 1 || key < 1 || key > 3) {
        std::cout << "Ошибка ввода!" << std::endl;
        scanf("%s", s);
    }
    return key;
}

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    PaymentPoint toll;
    
    std::cout << "Объект Пункт оплаты" << std::endl;
    std::cout << "1. Сымитировать оплату проезда" << std::endl;
    std::cout << "2. Сымитировать недобросовестного водителя" << std::endl;
    std::cout << "3. Вывести итоговую информации о кол-ве машин и выручке" << std::endl;
    std::cout << "===================================" << std::endl;


    int key;
    do {
        key = getMenuItem();

        switch(key) {
            case 1:
                toll.payFare();
                break;
            case 2:
                toll.skipFare();
                break;
        }
    } while (key!=3);
    toll.getInfo();
}