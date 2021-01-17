#include<bits/stdc++.h>
using namespace std;

long long dp[31][31];

long long solve(int from, int to) {
	for (int i = from; i <= to; i++) {
		dp[from][i] = 1;
	}

	for (int i = from + 1; i <= to; i++) {
		for (int j = from + 1; j <= to; j++) {
			if (i <= j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[to][to];
}

int main() {
	int H, N;
	cin >> H >> N;

	if (N < H) cout << solve(N, H) << '\n';
	else cout << solve(H, N) << '\n';

	return 0;
}