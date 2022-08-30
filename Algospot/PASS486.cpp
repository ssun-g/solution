#include<bits/stdc++.h>
using namespace std;

int minFactorPower[10000001]; // 가장 작은 소인수의 개수
int minFactor[10000001]; // 가장 작은 소인수
int factor[10000001]; // 약수의 개수

void getEratos() {
	minFactor[0] = -1;
	minFactor[1] = -1;
	for (int i = 2; i <= 10000000; i++) {
		minFactor[i] = i;
	}

	for (int i = 2; i <= sqrt(10000000); i++) {
		if (minFactor[i] == i) {
			for (int j = i*i; j <= 10000000; j += i) {
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}

	factor[1] = 1;
	for (int i = 2; i <= 10000000; i++) {
		if (minFactor[i] == i) {
			minFactorPower[i] = 1;
			factor[i] = 2;
		}
		else {
			int divide = i / minFactor[i];
			if (minFactor[i] != minFactor[divide])
				minFactorPower[i] = 1;
			else
				minFactorPower[i] = minFactorPower[divide] + 1;

			int a = minFactorPower[i];
			factor[i] = factor[divide] * (a + 1) / a;
		}
	}
}

void getBruteForce() {
	for (int i = 1; i <= 10000000; i++) {
		for (int j = i; j <= 10000000; j += i) {
			factor[j] += 1;
		}
	}
}

int main() {
	getEratos();
	//getBruteForce();

	int c;
	cin >> c;
	while (c--) {
		int answer = 0;
		int n, lo, hi;
		cin >> n >> lo >> hi;

		for (int i = lo; i <= hi; i++) {
			if (n == factor[i]) answer++;
		}

		cout << answer << '\n';
	}

	return 0;
}