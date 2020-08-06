#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double Normal(double mean, double sigma, double x) {
	double ERF = erf((x - mean) / (sigma*sqrt(2)));
	return (1 + ERF) / 2;
}


int main() {
	double m, s, a, b;
	scanf("%lf %lf %lf %lf", &m, &s, &a, &b);
	printf("%.2f\n", (1 - Normal(m, s, a)) * 100);
	printf("%.2f\n", (1 - Normal(m, s, b)) * 100);
	printf("%.2f\n", Normal(m, s, b) * 100);

	return 0;
}
