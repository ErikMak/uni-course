/*
Author: ErikMak
Task:

Промоделировать отливку листов стали. Листы стали характеризуются толщиной (в мм) и плотностью стали (в кг/м3).
Листы делятся на квадратные, прямоугольные и треугольные. Определите виртуальные методы,
возвращающие вес, площадь и информацию о листе. создайте массив из 15 листов стали, создав 5 квадратных, 
7 прямоугольных и 3 треугольных листа случайных размеров. Выведите информацию о каждом листе и 
посчитайте суммарную площадь и суммарный вес всех листов. 

*/

#include <iostream>
#include <windows.h>
#include <vector>
#include <ctime>

// Класс характеризующий прямоугольный стальпрокат 
class RolledSteel { 
    protected:
        static int thickness; // толщина в mm
        static int density;   // плотность в kg/m^3

        int sa, sb; // размеры листа в mm
    public: 
        RolledSteel(int const a, int const b);
        // Получить площадь листа (в m^2)
        virtual float getArea();
        // Получить вес листа (в kg)
        float getWeight();
        // Вывести информацию
        void getInfo();
}; 

// Класс характеризующий квадратные листы
class SquareSteel : public RolledSteel {
    public:
        SquareSteel(int const a) : RolledSteel(a, a) { }
};

// Класс характеризующий треугольные листы
class TriangleSteel : public RolledSteel {
    public:
        TriangleSteel(int const a, int const b) : RolledSteel(a, b) { }
        // Переопределение виртуальной функции getArea
        float getArea() override;
};

RolledSteel::RolledSteel (int const a, int const b) {
    sa = a; sb = b;
}
float RolledSteel::getArea() {
    return (sa * sb) / 1000000;
}
float RolledSteel::getWeight() {
    return getArea() * thickness / 1000 * density;
}
void RolledSteel::getInfo() {
    std::cout << "Ширина/высота: " << sa << "x" << sb << " mm" << std::endl;
    std::cout << "Толщина листа: " << thickness << " mm" << std::endl;
    std::cout << "Плотность листа: " << density << " kg/m^3" << std::endl;
    std::cout << "Площадь листа: " << getArea() << " m^2" << std::endl;
    std::cout << "Вес листа: " << getWeight() << " kg" << std::endl;
    std::cout << "===================================" << std::endl;
}

float TriangleSteel::getArea() {
    return (0.5 * this->getArea());
}

// Создать quantity прямоугольных листов
void addRectangleSteel(int const quantity, std::vector<RolledSteel>& produce) {
    int a, b;
    for(int i = 0; i < quantity; i++) {
        // Генерация случайного размера стальпроката
        a = (1 + rand() % 10) * 1000;
        b = (1 + rand() % 10) * 1000;

        produce.push_back(RolledSteel(a, b));
    }
};
// Создать quantity квадратных листов
void addSquareSteel(int const quantity, std::vector<RolledSteel>& produce) {
    int a;
    for(int i = 0; i < quantity; i++) {
        // Генерация случайного размера стальпроката
        a = (1 + rand() % 10) * 1000;

        produce.push_back(SquareSteel(a));
    }
};
// Создать quantity треугольных листов
void addTriangleSteel(int const quantity, std::vector<RolledSteel>& produce) {
    int a, b;
    for(int i = 0; i < quantity; i++) {
        // Генерация случайного размера стальпроката
        a = (1 + rand() % 10) * 1000;
        b = (1 + rand() % 10) * 1000;

        produce.push_back(TriangleSteel(a, b));
    }
};

// Инициализация статических переменных
int RolledSteel::thickness = 4;
int RolledSteel::density = 7900;

int main () {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    std::vector<RolledSteel> produce; 

    addRectangleSteel(7, produce);
    addSquareSteel(5, produce);
    addTriangleSteel(3, produce);

    float total_weight, total_area = 0;
    std::cout << "==Информация по готовой продукции==" << std::endl;
    for(unsigned int i = 0; i < produce.size(); i++) {
        produce[i].getInfo();
        total_weight+=produce[i].getWeight();
        total_area+=produce[i].getArea();
    }
    std::cout << "Суммарный вес листов: " << total_weight << " kg" << std::endl;
    std::cout << "Суммарная площадь листов: " << total_area << " m^2" << std::endl;
}