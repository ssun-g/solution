#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	double a, b;
	int n;
	scanf("%lf %lf", &a, &b);
	scanf("%d", &n);

	double p = a / b;
	double q = 1 - p;
	printf("%.3f\n", pow(q, n - 1)*p);

	return 0;
}
