#include<cstdio>
#include<algorithm>
using namespace std;

int arr[300], dp[300];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(arr[i - 1] + arr[i] + dp[i - 3], arr[i] + dp[i - 2]);
	}

	printf("%d\n", dp[n - 1]);

	return 0;
}