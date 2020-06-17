#include<cstdio>
#include<algorithm>
using namespace std;

int arr[10000];
int dp[10000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	printf("%d\n", dp[n]);

	return 0;
}