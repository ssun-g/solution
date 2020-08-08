#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double X[100];
double Y[100];

int main() {
	int n;
	double sum = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { // input & calculate the mean in X
		scanf("%lf", &X[i]);
		sum += X[i];
	}
	double mean_x = sum / n;

	sum = 0.0;
	for (int i = 0; i < n; i++) { // calculate the standard deviation in X
		sum += pow(X[i] - mean_x, 2);
	}
	double sd_x = sqrt(sum / n);

	sum = 0.0;
	for (int i = 0; i < n; i++) { // input & calculate the mean in Y
		scanf("%lf", &Y[i]);
		sum += Y[i];
	}
	double mean_y = sum / n;

	sum = 0.0;
	for (int i = 0; i < n; i++) { // calculate the standard deviation in Y
		sum += pow(Y[i] - mean_y, 2);
	}
	double sd_y = sqrt(sum / n);

	double pcc = 0.0;
	for (int i = 0; i < n; i++) {
		pcc += (X[i] - mean_x)*(Y[i] - mean_y);
	}

	printf("%.3f\n", pcc / (n*sd_x*sd_y));

	return 0;
}
