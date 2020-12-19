#include<bits/stdc++.h>
using namespace std;

long long dp[1001];

long long move(int n) {
	long long ret = LLONG_MAX;
	if (n == 1) return 1;

	for (int i = 1; i < n; i++) {
		if (n - i >= 63) continue;
		dp[i] = (dp[i] == 0) ? move(i) : dp[i];
		long long rMove = dp[i];
		long long nrMove = pow(2, n - i) - 1;
		ret = min(ret, 2 * rMove + nrMove);
	}

	return ret;
}

int main() {
	int n, cnt = 1;
	while (cin >> n) {
		cout << "Case " << cnt++ << ": " << move(n) << '\n';
	}

	return 0;
}