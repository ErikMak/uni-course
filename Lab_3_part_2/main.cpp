/*
Author: ErikMak
Task:

Промоделировать стрельбу по мишени группой человек. Каждый человек имеет своё имя, возраст и стаж обучения стрельбе. 
Люди делятся на новичков, опытных и ветеранов. Для каждого человека определите метод "Стрелять", возвращающий значение 
(попал - true, не попал - false). Попадание определяется случайным образом, причём для новичка вероятность попасть 
равна 0.01 * стаж обучения стрельбе; для опытного = 0.05 * стаж обучения стрельбе; для ветерана = 0.9 - 0.01 * возраст.
Люди стреляют по очереди, пока кто - то не попадёт в мишень. Стрельба прекращается после того, 
как кто - то попал или все выстрелили по одному разу.

*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <windows.h>

// Класс характеризующий стрелка
class Human {
    protected:
        std::string name;
        int age;
        int skill; // опыт стрелка
    public:
        Human(std::string const _name, int const _age, int const _skill);
        // Произвести выстрел
        virtual bool shoot();
        // Вывести информацию
        void getInfo() const;
};

// Класс характеризующий стрелка-новичка
class Newbie : public Human {
    public:
        Newbie(std::string const _name, int const _age, int const _skill)\
        : Human(_name, _age, _skill) { }

        bool shoot() override {
            // Просчет вероятности попадания
            float probability = 0.01 * skill;
            // Возврат статуса "попал" (true) или "не попал" (false)
            bool is_hit =  1 + rand() % 100 < (probability * 100);
            return is_hit;
        }
};

// Класс характеризующий опытного стрелка
class SkilledMan : public Human {
    public:
        SkilledMan(std::string const _name, int const _age, int const _skill)\
        : Human(_name, _age, _skill) { }

        bool shoot() override {
            // Просчет вероятности попадания
            float probability = 0.05 * skill;
            // Возврат статуса "попал" (true) или "не попал" (false)
            bool is_hit =  1 + rand() % 100 < (probability * 100);
            return is_hit;
        }
};

// Класс характеризующий стрелка-ветерана
class Veteran : public Human {
    public:
        Veteran(std::string const _name, int const _age, int const _skill)\
        : Human(_name, _age, _skill) { }

        bool shoot() override {
            // Просчет вероятности попадания
            float probability = 0.9 - 0.01 * age;
            // Возврат статуса "попал" (true) или "не попал" (false)
            bool is_hit =  1 + rand() % 100 < (probability * 100);
            return is_hit;
        }
};

Human::Human(std::string const _name, int const _age, int const _skill) {
    name = _name; age = _age; skill = _skill;
}

bool Human::shoot() {
    return false;
}

void Human::getInfo() const {
    std::cout << "Имя стрелка: " << name << std::endl;
    std::cout << "Возвраст: " << age << " лет"<< std::endl;
    std::cout << "Опыт стрельбы: " << skill << " лет"<< std::endl;
    std::cout << "===================================" << std::endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    const unsigned int size = 5;
    Human *shooter[size] = {
        new Newbie("Michael", 18, 1),
        new SkilledMan("Alexander", 33, 10),
        new Veteran("William", 52, 34),
        new SkilledMan("Adam", 40, 15),
        new Newbie("Joe", 22, 3)
    };

    for(unsigned int i = 0; i < size; i++) {
        shooter[i]->getInfo();
        if(shooter[i]->shoot()) {
            std::cout << "Стрелок попал в мишень!" << std::endl;
            std::cout << std::endl;
            break;
        } else {
            std::cout << "Стрелок промахнулся!" << std::endl; 
            std::cout << std::endl;
        }
    }
}