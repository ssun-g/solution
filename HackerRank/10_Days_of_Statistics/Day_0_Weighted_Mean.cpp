#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];
int weight[50];

int main() {
	int n;
	double sumX = 0;
	double sumWei = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
		sumWei += weight[i];
	}

	for (int i = 0; i < n; i++) {
		sumX += arr[i] * weight[i];
	}

	printf("%.1f", sumX / sumWei);

	return 0;
}
