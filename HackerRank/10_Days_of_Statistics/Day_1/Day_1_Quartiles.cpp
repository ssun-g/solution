#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];
int X[5001];

int main() {
	int n;
	int idx = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		int fq;
		scanf("%d", &fq);
		for (int j = 0; j<fq; j++) {
			X[idx++] = arr[i];
		}
	}
	sort(X, X + idx + 1);

	int mid = idx / 2;
	bool isOdd = false;
	if (idx % 2 == 1) {
		mid = idx / 2 + 1;
		isOdd = true;
	}

	double Q1, Q3;
	if (isOdd) {
		if (mid % 2 == 1) {
			Q1 = (X[mid / 2] + X[mid / 2 + 1]) / 2;
			Q3 = (X[(mid + idx) / 2] + X[(mid + idx) / 2 + 1]) / 2;
		}
		else {
			Q1 = X[mid / 2];
			Q3 = X[(mid + idx) / 2 + 1];
		}
	}
	else {
		if (mid % 2 == 1) {
			Q1 = X[mid / 2 + 1];
			Q3 = X[(mid + idx) / 2 + 1];
		}
		else {
			Q1 = (X[mid / 2] + X[mid / 2 + 1]) / 2;
			Q3 = (X[(mid + idx) / 2] + X[(mid + idx) / 2 + 1]) / 2;
		}
	}
	printf("%.1f", Q3 - Q1);

	return 0;
}
