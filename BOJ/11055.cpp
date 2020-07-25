#include<cstdio>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n;
	int MAX = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		MAX = (MAX < dp[i]) ? dp[i] : MAX;
	}
	printf("%d\n", MAX);

	return 0;
}