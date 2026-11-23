#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	
	vector<vector<double>> X = {{2,0,1},{1,1,1},{1,0,1},{0,1,1}};
	vector<double> Y = {2,1,1,0};
	vector<double> w = {0.5, 0.1, -0.3};
	double lr = 0.01;
	int n = X.size();

	vector<double> dW(3, 0.0);
	for (int i = 0; i < n; i++) {
		double pred = w[0]*X[i][0] + w[1]*X[i][1] + w[2]*X[i][2];
		double err = pred - Y[i];
		for (int j = 0; j < 3; j++)
			dW[j] += err * X[i][j];
	}

	for (int j = 0; j < 3; j++) {
		w[j] -= lr * dW[j] / n;
		cout << "w[" << j << "] = " << w[j] << endl;
	}
	return 0;
}