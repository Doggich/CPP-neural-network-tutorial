#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);

	double sum = 2.5;
	cout << "Регрессия, без sigmoid: " << sum << endl;
	cout << "Регрессия, с sigmoid:   " << 1.0/(1.0+exp(-sum)) << " (сжалось!)" << endl;

	cout << "\nКлассификация:" << endl;
	cout << "  sigmoid(-10) = " << 1.0/(1.0+exp(10)) << " (почти 0 — 'нет')" << endl;
	cout << "  sigmoid(0)   = " << 1.0/(1.0+exp(0))  << " (0.5 — 'не знаю')" << endl;
	cout << "  sigmoid(10)  = " << 1.0/(1.0+exp(-10)) << " (почти 1 — 'да')" << endl;
	return 0;
}