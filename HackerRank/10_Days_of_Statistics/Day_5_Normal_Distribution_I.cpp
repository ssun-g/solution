#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double Normal(double mean, double s, double x) {
	double ERF = erf((x - mean) / (s*sqrt(2)));
	return (1 + ERF) / 2;
}

int main() {
	double m, sig, x, lower, upper;
	scanf("%lf %lf %lf %lf %lf", &m, &sig, &x, &lower, &upper);
	printf("%.3f\n", Normal(m, sig, x));
	printf("%.3f\n", Normal(m, sig, upper) - Normal(m, sig, lower));

	return 0;
}
