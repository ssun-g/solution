#include<cstdio>
#include<algorithm>
using namespace std;

int dp[10001];
int pan[10001];

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &pan[i]);
	}
	dp[1] = pan[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + pan[j]);
		}
	}
	printf("%d\n", dp[n]);

	return 0;
}