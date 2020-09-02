#include<cstdio>
using namespace std;

int dp[31];

int main() {
	int n;
	int answer;
	scanf("%d", &n);
	dp[0] = 1;
	dp[2] = 3;
	if (n % 2 == 1) answer = 0;
	else {
		for (int i = 2; 2 * i <= n; i++) {
			dp[2 * i] = dp[2 * (i - 1)] * 3;
			for (int j = 2; j <= i; j++) {
				dp[2 * i] += dp[2 * i - 2 * j] * 2;
			}

		}
		answer = dp[n];
	}
	printf("%d\n", answer);

	return 0;
}