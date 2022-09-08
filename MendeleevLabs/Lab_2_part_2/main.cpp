/*
Author: ErikMak
Task:

Реализовать класс Matrix, позволяющий работать с матрицами систем однородных линейных уравнений. В классе должны быть переопределены с помощью ключевого слова operator следующие операции:
	- сложение двух матриц
	- вычитание одной матрицы из другой
	- умножение матриц;
	- умножение матрицы на число.
Также данный класс должен содержать в себе метод, осуществляющий транспонирование матрицы.

*/

#include <iostream>
#include <windows.h>
#include <ctime>

class Matrix {
    private:
        int **mtx;
        int size_m;
        int size_n;
    public:
        // Class constructor; allocate memory
        Matrix(const int M, const int N);
        // Send values
        void input();
        // Formated output
        void output();
        // Overloading the + operator 
        Matrix operator+ (const Matrix &right) const;
        // Overloading the = operator 
        Matrix operator- (const Matrix &right) const;
        // Overloading the * operator 
        Matrix operator* (const Matrix &right) const;
        // Overloading the * operator (* by number)
        Matrix operator* (const int num) const;
        // Transpose the matrix
        Matrix transpose () const;
        // Overloading the = operator 
        Matrix &operator= (const Matrix &right);
        // Class destructor; release memory
        ~Matrix();
};

Matrix::Matrix(const int M, const int N){
    size_m = M; size_n = N;
        mtx = new int *[size_m];
        for(int i = 0; i < size_m; i++)
            mtx[i] = new int[size_n];
}
void Matrix::input() {
    for(int i = 0; i < size_m; i++) {
        for(int j =0; j < size_n; j++) {
            // Assign a random value
            mtx[i][j] = (1 + rand() % 20) - 10;
        }
    }
}
void Matrix::output() {
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j<size_n; j++){
            std::cout.width(3);
            std::cout << mtx[i][j];
        }
        std::cout << std::endl;
    }
}
Matrix Matrix::operator+ (const Matrix &right) const {
    if(right.size_m != this->size_m || right.size_n != this->size_n) { // Validation
        throw "Матрицы разного размера!";
    }
    Matrix tmp(size_m, size_n);
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j<size_n; j++){
            tmp.mtx[i][j] = mtx[i][j] + right.mtx[i][j];
        }
    }
    return tmp;
}
Matrix Matrix::operator- (const Matrix &right) const {
    if(right.size_m != this->size_m || right.size_n != this->size_n) { // Validation
        throw "Матрицы разного размера!";
    }
    Matrix tmp(size_m, size_n);
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j<size_n; j++){
            tmp.mtx[i][j] = mtx[i][j] - right.mtx[i][j];
        }
    }
    return tmp;
}
Matrix Matrix::operator* (const Matrix &right) const {
    if(this->size_m != right.size_n) { // Validation
        throw "Количество столбцов первой матрицы не равно количеству строк второй матрицы!";
    }
    int val;
    Matrix tmp(size_m, right.size_n);
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j< right.size_n; j++){
            val = 0;
            for(int k = 0; k < size_n; k++) {
                val += mtx[i][k] * right.mtx[k][j];
            }
            tmp.mtx[i][j] = val;
        }
    }
    return tmp;
}
Matrix Matrix::operator* (const int num) const {
    Matrix tmp(size_m, size_n);
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j<size_n; j++){
            tmp.mtx[i][j] = mtx[i][j] * num;
        }
    }
    return tmp;
}
Matrix &Matrix::operator= (const Matrix &right) {
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j<size_n; j++){
            mtx[i][j] = right.mtx[i][j];
        }
    }
    return (*this);
}
Matrix Matrix::transpose() const {
    Matrix tmp(size_n, size_m);
    for(int i=0; i<size_m; i++) {
        for(int j = 0; j<size_n; j++){
            tmp.mtx[j][i] = mtx[i][j];
        }
    }
    return tmp;
}
Matrix::~Matrix() {
    for(int i = 0; i < size_m; i++)
        delete []mtx[i];
    delete []mtx;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    Matrix a(2, 2), b(2, 2);
    std::cout << "==========Первая матрица========" << std::endl;
    a.input();
    a.output();
    std::cout << "==========Вторая матрица========" << std::endl;
    b.input();
    b.output();
    try {
        std::cout << "============Сложение============" << std::endl;
        Matrix c = a + b;
        c.output();
        std::cout << "============Вычитание===========" << std::endl;
        Matrix d = a - b;
        d.output();
        std::cout << "============Умножение===========" << std::endl;
        Matrix e = a * b;
        e.output();
        std::cout << "=======Умножение на число=======" << std::endl;
        int num = (1 + rand() % 20) - 10;
        std::cout << "Число: " << num << std::endl;
        Matrix f = a * num;
        f.output();
        std::cout << "========Транспонирование========" << std::endl;
        Matrix u = a.transpose();
        u.output();
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}