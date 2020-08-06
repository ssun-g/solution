#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long factorial(int a, int b) {
	long long n = 1, r1 = 1, r2 = 1;
	for (int i = 1; i <= a; i++) n *= (long long)i;
	for (int i = 1; i <= b; i++) r1 *= (long long)i;
	for (int i = 1; i <= (a - b); i++) r2 *= (long long)i;

	return (n / (r1*r2));
}

int main() {
	double ans_f = 0.0;
	double ans_s = 0.0;
	for (int i = 0; i < 3; i++) {
		ans_f += factorial(10, i)*pow(0.12, i)*pow(0.88, 10 - i);
	}
	for (int i = 0; i <= 1; i++) {
		ans_s += factorial(10, i)*pow(0.12, i)*pow(0.88, 10 - i);
	}
	ans_s = 1 - ans_s;
	printf("%.3f\n%.3f", ans_f, ans_s);

	return 0;
}
