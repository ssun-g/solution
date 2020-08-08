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
	double tickets, students, mean, sd;
	scanf("%lf %lf %lf %lf", &tickets, &students, &mean, &sd);

	double nmean = mean*students;
	double nsd = sd*sqrt(students);
	printf("%.4f\n", Normal(nmean, nsd, tickets));

	return 0;
}
