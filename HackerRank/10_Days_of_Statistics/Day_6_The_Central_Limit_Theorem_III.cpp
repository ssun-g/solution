#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int  main() {
	double n = 100;
	double mean = 500;
	double sd = 80;
	double zscore = 1.96;
	double e = (sd / sqrt(n))*zscore;

	printf("%.2f\n", mean - e);
	printf("%.2f\n", mean + e);

	return 0;
}