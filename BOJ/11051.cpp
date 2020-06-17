#include<cstdio>
using namespace std;

int arr[1001][1001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0 || j == i) arr[i][j] = 1;
			else arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
		}
	}
	printf("%d\n", arr[n][k]);

	return 0;
}