#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);

	double x1 = 2, x2 = 0, x3 = 1;
	double w1 = 0.5, w2 = 0.1, w3 = -0.3;
	double b = 0.0;          // ← bias
	double target = 2;
	double lr = 0.01;

	double pred = w1*x1 + w2*x2 + w3*x3 + b;
	double err  = pred - target;

	w1 -= lr * err * x1;
	w2 -= lr * err * x2;
	w3 -= lr * err * x3;
	b  -= lr * err;          // ← bias тоже крутится

	cout << "b = " << b << endl;
	return 0;
}