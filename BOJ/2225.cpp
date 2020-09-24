#include<cstdio>
using namespace std;

long long dp[201][201];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= 1000000000;
			}
		}
	}
	printf("%lld\n", dp[K][N]);

	return 0;
}