#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	
	double x1 = 2, x2 = 0, x3 = 1;
	double w1 = 0.5, w2 = 0.1, w3 = -0.3;
	double target = 2;   // правильный ответ

	double pred = w1*x1 + w2*x2 + w3*x3;
	double err  = pred - target;

	cout << "Предсказание: " << pred << endl;
	cout << "Ошибка: " << err << endl;

	double lr = 0.01;
	w1 = w1 - lr * err * x1;   // крутим ТОЛЬКО w1

	double pred2 = w1*x1 + w2*x2 + w3*x3;
	cout << "Новый w1: " << w1 << endl;
	cout << "Новое предсказание: " << pred2 << endl;
	return 0;
}