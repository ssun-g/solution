#include<cstdio>
#include<algorithm>
using namespace std;

int arr[101][10001];
int time[101];
int score[101];

int main() {
	int n, t;
	int ans = 0;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &time[i], &score[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			arr[i][j] = arr[i - 1][j];
			if (j - time[i] >= 0) {
				arr[i][j] = max(arr[i][j], arr[i - 1][j - time[i]] + score[i]);
			}
			ans = max(ans, arr[i][j]);
		}
	}
	printf("%d\n", ans);

	return 0;
}