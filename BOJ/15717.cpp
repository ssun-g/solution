#include<bits/stdc++.h>
using namespace std;

long long dduk(long long mul, long long n) {
	if (n == 0 || n == -1) return 1;

	long long ret = 1;
	while (n) {
		if (n % 2 == 1) ret = ret * mul % 1000000007;
		mul = mul * mul % 1000000007;
		n /= 2;
	}

	return ret;
}

int main() {
	long long N;
	cin >> N;
	cout << dduk(2, N - 1) << '\n';

	return 0;
}