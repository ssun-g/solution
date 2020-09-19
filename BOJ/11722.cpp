#include<cstdio>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int answer = 1;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				answer = (answer < dp[i]) ? dp[i] : answer;
			}
		}
	}
	printf("%d", answer);

	return 0;
}