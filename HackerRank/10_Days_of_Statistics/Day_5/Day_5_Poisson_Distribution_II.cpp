#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.3f\n", 160 + 40 * ((a*a) + a));
	printf("%.3f\n", 128 + 40 * ((b*b) + b));

	return 0;
}
