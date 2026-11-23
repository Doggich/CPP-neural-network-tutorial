#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);

	double x[3] = {2, 0, 1};
	double w[3] = {0.5, 0.1, -0.3};
	double target = 2;
	double lr = 0.01;

	double pred = w[0]*x[0] + w[1]*x[1] + w[2]*x[2];
	double err  = pred - target;

	cout << "Ошибка: " << err << endl;

	for (int j = 0; j < 3; j++) {
		w[j] = w[j] - lr * err * x[j];
		cout << "w[" << j << "] = " << w[j] << endl;
	}
	return 0;
}