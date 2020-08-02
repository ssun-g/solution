#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double arr[100];

int main() {
	int n;
	double sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
		sum += arr[i];
	}

	double mean = sum / n;
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow(arr[i] - mean, 2);
	}
	printf("%.1f", sqrt(sum / n));

	return 0;
}
