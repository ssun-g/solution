#include<cstdio>
#include<algorithm>
using namespace std;

int arr[1001];
int inc_dp[1001];
int dec_dp[1001];

int main() {
	int answer = 0;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		inc_dp[i] = 1;
		dec_dp[N - 1 - i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && inc_dp[i] < inc_dp[j] + 1)
				inc_dp[i] = inc_dp[j] + 1;
			if (arr[N - 1 - i] > arr[N - 1 - j] && dec_dp[N - 1 - i] < dec_dp[N - 1 - j] + 1)
				dec_dp[N - 1 - i] = dec_dp[N - 1 - j] + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		answer = max(answer, inc_dp[i] + dec_dp[i]);
	}
	printf("%d", answer - 1);

	return 0;
}