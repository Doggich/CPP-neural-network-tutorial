#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
    
using namespace std;

int main() {
	SetConsoleOutputCP(65001);

	// XOR: классика, которую линейная формула не решает
	vector<vector<double>> X = {{0,0},{0,1},{1,0},{1,1}};
	vector<double> Y = {0,1,1,0};

	vector<double> w(2);
	w[0] = 0.5; w[1] = -0.3;
	double b = 0.0;
	double lr = 0.1;
	int n = X.size();

	for (int e = 0; e < 100000; e++) {
		vector<double> dW(2, 0.0);
		double dB = 0.0;
		double total_err = 0.0;

		for (int i = 0; i < n; i++) {
			double pred = b + w[0]*X[i][0] + w[1]*X[i][1];
			double err = pred - Y[i];
			total_err += fabs(err);
			for (int j = 0; j < 2; j++) dW[j] += err*X[i][j];
			dB += err;
		}
		for (int j = 0; j < 2; j++) w[j] -= lr*dW[j]/n;
		b -= lr*dB/n;

		if (e == 0 || e == 999 || e == 9999 || e == 99999)
			cout << "эпоха " << e+1 << ": MAE = " << total_err << endl;
	}

	cout << "\nXOR линейной сетью (без sigmoid):\n";
	for (int i = 0; i < n; i++) {
		double pred = b + w[0]*X[i][0] + w[1]*X[i][1];
		cout << "  [" << X[i][0] << "," << X[i][1] << "] -> "
			 << pred << " (надо " << Y[i] << ")\n";
	}
	return 0;
}