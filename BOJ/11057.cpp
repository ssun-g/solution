#include<cstdio>
using namespace std;

int arr[1001][10];

int main() {
	int n, ans = 0;
	scanf("%d", &n);

	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				arr[i][j] = (arr[i][j] + arr[i - 1][k]) % 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		ans = (ans + arr[n][i]) % 10007;
	}
	printf("%d\n", ans);

	return 0;
}
