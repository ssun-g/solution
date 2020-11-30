#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n) {
	if (n == 1 || n == 0) return 1;
	return factorial(n - 1) * n;
}

double binomial(int x, int n, double p, double q) {
	double f = (factorial(n) / (factorial(x)*factorial(n - x)));
	return f*pow(p, x)*pow(q, n - x);
}


int main() {
	double p = 1.09 / (1.09 + 1);
	double q = 1 - p;
	double probability = 0.0;
	for (int i = 3; i <= 6; i++) {
		probability += binomial(i, 6, p, q);
	}
	printf("%.3f", probability);

	return 0;
}
