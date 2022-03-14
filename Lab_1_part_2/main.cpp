/*
Author: ErikMak
Task:

Описать и применить к матрице A размера M x N процедуру DellJ(A, M, N, i, j), 
удаляющую строку и столбец, содержащие элемент A[i][j] (если i > M или j > N, 
то матрица не изменяется). Вывести полученную матрицу.

*/

#include <iostream>
#include <windows.h>

void DellJ(float **&A, int &M, int &N, int i, int j){
    if(i > M || j > N) { // Validate
        return;
    } 
    std::cout << "Строка: " << i << "\tСтолбец: " << j << std::endl;

    float **tmp = new float *[M-1]; // New temp array
    for(int k = 0; k < M-1; k++)
        tmp[k] = new float [N-1];

    int a_row = 0;
    int a_col = 0;
    for(int m=0; m<M; m++){
        a_col = 0;
        if(m != i-1) {
            for(int n=0; n<N; n++){
                if(n != j-1) {
                    tmp[a_row][a_col] = A[m][n];
                    a_col++;
                }
            }
            a_row++;
        }
    }
    // Release memory of primary array
    for(int i = 0; i < M; i++) {
        delete []A[i];
    }
    delete []A;
    --M; --N;
    A = tmp; // Send by address-of operator
}
void printArr(float **A, const int M, const int N){
    for(int i=0; i<M; i++) {
        for(int j = 0; j<N; j++){
            std::cout.width(2);
            std::cout << A[i][j];
        }
        std::cout << std::endl;
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int M, N;
    do { // Validate
        std::cout << "Количество строк: ";
        std::cin >> M;
    } while (M <= 1);
    do {
        std::cout << "Количество столбцов: ";
        std::cin >> N;
    } while (N <= 1);

    // Allocate memory for primary array
    float **A = new float *[M];
    for(int i = 0; i < M; i++)
        A[i] = new float [N];

    // Input array
    std::cout << "========================" << std::endl;
    for(int i=0; i<M; i++){
        std::cout << "Ввод " << i+1 << " строки:" << std::endl;
        for(int j=0; j<N; j++){
            std::cin >> A[i][j];
        }
    }
    std::cout << "========================" << std::endl;
    printArr(A, M, N);
    int i, j;
    std::cout << "Введите i (строка): ";
    std::cin >> i;
    std::cout << "Введите j (столбец): ";
    std::cin >> j;
    DellJ(A, M, N, i, j);

    // Output result
    std::cout << "========================\nРезультат:" << std::endl;
    printArr(A, M, N);

    // Release memory of new array
    for(int i = 0; i < M; i++) {
        delete []A[i];
    }
    delete []A;
    return 0;
}
