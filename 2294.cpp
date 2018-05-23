#include <cstdio>
#include<algorithm>
using namespace std;

int coin[100];
int dp[10001];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
		for (int j = 0; j < n; j++) {
			int before = i - coin[j];
			if (before >= 0 && dp[before] != 10001) {
				dp[i] = min(dp[i], dp[before] + 1);
			}
		}
	}
	printf("%d\n", dp[k] == 10001 ? -1 : dp[k]);

	return 0;
}