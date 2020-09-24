#include<cstdio>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int answer = 1;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				answer = max(answer, dp[i]);
			}
		}
	}
	printf("%d", answer);

	return 0;
}