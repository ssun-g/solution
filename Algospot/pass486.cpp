#include<bits/stdc++.h>
using namespace std;

int factor[10000001];

int getFactor(int n, int lo, int hi) {
	int cnt = 0;
	for (int i = lo; i <= hi; i++) {
		if (n == factor[i]) cnt++;
	}

	return cnt;
}

int main() {
	for (int i = 1; i <= 10000000; i++) {
		for (int j = i; j <= 10000000; j += i) {
			factor[j] += 1;
		}
	}

	int c;
	cin >> c;
	while (c--) {
		int n, lo, hi;
		cin >> n >> lo >> hi;

		cout << getFactor(n, lo, hi) << '\n';
	}

	return 0;
}