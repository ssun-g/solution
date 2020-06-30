#include<cstdio>
using namespace std;

int main() {
	int n;
	int dp[1001] = { 0, };
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 1) dp[i] = (dp[i - 1] * 2 - 1) % 10007;
		else dp[i] = (dp[i - 1] * 2 + 1) % 10007;
	}
	printf("%d\n", dp[n]);

	return 0;
}