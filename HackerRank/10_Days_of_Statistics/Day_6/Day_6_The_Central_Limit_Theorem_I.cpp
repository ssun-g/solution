#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double Normal(double m, double s, double x) {
	double ERF = erf((x - m) / (s*sqrt(2)));
	return (1 + ERF) / 2;
}


int main() {
	double max_weight, num, mean, sd;
	scanf("%lf %lf %lf %lf", &max_weight, &num, &mean, &sd);

	double nmean = num*mean;
	double nsd = sqrt(num)*sd;

	printf("%.4f\n", Normal(nmean, nsd, max_weight));

	return 0;
}
