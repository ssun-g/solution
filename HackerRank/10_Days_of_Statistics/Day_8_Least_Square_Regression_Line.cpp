#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double X[5] = { 95, 85, 80, 70, 60 };
double Y[5] = { 85, 95, 70, 65, 70 };

int main() {
	double sum_xy = 0.0;
	double sum_x = 0.0;
	double sum_y = 0.0;
	double sum_xx = 0.0;

	for (int i = 0; i < 5; i++) {
		sum_xy += X[i] * Y[i];
		sum_x += X[i];
		sum_y += Y[i];
		sum_xx += X[i] * X[i];
	}

	double b = ((5 * sum_xy) - (sum_x*sum_y)) / ((5 * sum_xx) - (sum_x*sum_x));
	double a = (sum_y / 5) - (b*sum_x / 5);

	printf("%.3f\n", a + b * 80);

	return 0;
}
