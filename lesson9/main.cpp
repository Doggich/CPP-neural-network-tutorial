#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// ---------- ОБУЧЕНИЕ ----------
void train(const vector<vector<double>>& X, const vector<double>& Y,
		   vector<double>& w, double& b, double lr, int epochs) {
	int n = X.size();
	int m = X[0].size();

	for (int e = 0; e < epochs; e++) {
		vector<double> dW(m, 0.0);
		double dB = 0.0;
		double total_err = 0.0;

		for (int i = 0; i < n; i++) {
			double pred = b;
			for (int j = 0; j < m; j++) pred += w[j]*X[i][j];
			double err = pred - Y[i];
			total_err += fabs(err);
			for (int j = 0; j < m; j++) dW[j] += err*X[i][j];
			dB += err;
		}

		for (int j = 0; j < m; j++) w[j] -= lr*dW[j]/n;
		b -= lr*dB/n;

		if (e == 0 || e == 9 || e == 99 || e == 999 || e == 9999 || e == epochs-1)
			cout << "эпоха " << e+1 << ": MAE = " << total_err << endl;
	}
}

// ---------- ПРЕДСКАЗАНИЕ ----------
double predict(const vector<double>& x, const vector<double>& w, double b) {
	double pred = b;
	for (size_t j = 0; j < x.size(); j++) pred += w[j]*x[j];
	return pred;
}

// ---------- СОХРАНЕНИЕ ----------
void save(const vector<double>& w, double b, const string& path) {
	ofstream out(path);
	for (double x : w) out << x << " ";
	out << b;
	out.close();
	cout << "Сохранено в " << path << endl;
}

// ---------- ЗАГРУЗКА (с проверкой) ----------
bool load(vector<double>& w, double& b, const string& path) {
	ifstream in(path);
	if (!in) return false;
	for (size_t j = 0; j < w.size(); j++)
		if (!(in >> w[j])) return false;   // проверка каждого чтения
	if (!(in >> b)) return false;
	in.close();
	return true;
}

int main() {
	SetConsoleOutputCP(65001);
	srand(time(0));

	vector<vector<double>> X = {{2,0,1},{1,1,1},{1,0,1},{0,1,1}};
	vector<double> Y = {2,1,1,0};
	int m = X[0].size();

	vector<double> w(m);
	double b = 0.0;

	if (!load(w, b, "weights.txt")) {
		cout << "Веса не найдены или файл битый — обучаем с нуля...\n";
		for (int j = 0; j < m; j++)
			w[j] = 2.0 * ((double)rand() / RAND_MAX) - 1.0;

		train(X, Y, w, b, 0.01, 100000);
		save(w, b, "weights.txt");
	} else {
		cout << "Веса загружены из weights.txt\n";
	}

	cout << "\nПредсказания на обучающих данных:\n";
	for (size_t i = 0; i < X.size(); i++)
		cout << "  " << predict(X[i], w, b) << " (надо " << Y[i] << ")\n";

	cout << "\nПредсказание на новых данных:\n";
	vector<vector<double>> newX = {{3,1,2},{5,2,3}};
	for (auto& x : newX)
		cout << "  [" << x[0] << "," << x[1] << "," << x[2] << "] -> "
			 << predict(x, w, b) << endl;

	return 0;
}