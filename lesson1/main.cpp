#include <iostream> 
#include <cstdlib> 
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    srand(time(NULL)); // запуск случайности

    // 1. ВХОДЫ 
    double x1 = 2, x2 = 0, x3 = 1;

    // 2. ВЕСА — СЛУЧАЙНЫЕ (сеть пока не знает правильных)
    double w1 = 2.0 * ((double)rand() / RAND_MAX) - 1.0;
    double w2 = 2.0 * ((double)rand() / RAND_MAX) - 1.0; 
    double w3 = 2.0 * ((double)rand() / RAND_MAX) - 1.0;

    // 3. ПРЕДСКАЗАНИЕ — формула 
    double pred = w1*x1 + w2*x2 + w3*x3;

    // 4. ВЫВОД 
    cout << "Случайные веса: " << w1 << " " << w2 << " " << w3 << endl; 
    cout << "Предсказание = " << pred << endl;

    return 0;
}