#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
		    
	vector<double> w = {13.6, -0.2, -6.6};
	double b = 0.5;

	// СОХРАНЕНИЕ
	ofstream out("weights.txt");
	for (double x : w) out << x << " ";
	out << b;
	out.close();
	cout << "Сохранено в weights.txt" << endl;

	// ЗАГРУЗКА — с проверкой каждого чтения
	vector<double> w2(3);
	double b2;
	ifstream in("weights.txt");
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		if (!(in >> w2[i])) { ok = false; break; }   // проверка!
	}
	if (ok && !(in >> b2)) ok = false;

	if (!ok) {
		cout << "Ошибка чтения файла!" << endl;
		return 1;
	}
	in.close();

	cout << "Загружено: ";
	for (double x : w2) cout << x << " ";
	cout << "| bias = " << b2 << endl;
	return 0;
}