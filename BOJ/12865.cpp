#include<cstdio>
#include<algorithm>
using namespace std;

int arr[101][100001];
int weight[101];
int value[101];

int main() {
	int n, k;
	int ans = -1;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			arr[i][j] = arr[i - 1][j];
			if (j - weight[i] >= 0) {
				arr[i][j] = max(arr[i][j], arr[i - 1][j - weight[i]] + value[i]);
			}
			ans = max(ans, arr[i][j]);
		}
	}
	printf("%d\n", ans);

	return 0;
}