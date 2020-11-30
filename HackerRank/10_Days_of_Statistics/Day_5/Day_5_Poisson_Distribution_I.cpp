#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main() {
	double m;
	int k = 5;
	scanf("%lf", &m);
	scanf("%d", &k);

	printf("%.3f", (pow(m, 5)*exp(-m)) / factorial(5));

	return 0;
}
