#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	
	vector<vector<double>> X = {{2,0,1},{1,1,1},{1,0,1},{0,1,1}};
	vector<double> Y = {2,1,1,0};
	vector<double> w = {0.5, 0.1, -0.3};
	double b = 0.0;
	double lr = 0.01;
	int n = X.size();

	for (int e = 0; e < 100000; e++) {
		vector<double> dW(3, 0.0);
		double dB = 0.0;
		double total_err = 0.0;

		for (int i = 0; i < n; i++) {
			double pred = b;
			for (int j = 0; j < 3; j++) pred += w[j]*X[i][j];
			double err = pred - Y[i];
			total_err += fabs(err);   // это MAE (без деления на n)
			for (int j = 0; j < 3; j++) dW[j] += err*X[i][j];
			dB += err;
		}

		for (int j = 0; j < 3; j++) w[j] -= lr*dW[j]/n;
		b -= lr*dB/n;

		// ВИЗУАЛИЗАЦИЯ СХОДИМОСТИ
		if (e == 0 || e == 9 || e == 99 || e == 999 || e == 9999 || e == 99999)
			cout << "эпоха " << e+1 << ": MAE = " << total_err << endl;
	}

	cout << "\nВеса: ";
	for (double x : w) cout << x << " ";
	cout << "| bias = " << b << endl;

	for (int i = 0; i < n; i++) {
		double pred = b;
		for (int j = 0; j < 3; j++) pred += w[j]*X[i][j];
		cout << pred << " (надо " << Y[i] << ")" << endl;
	}
	return 0;
}