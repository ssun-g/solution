#include<cstdio>
using namespace std;

int arr[301][301];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int k;
	scanf("%d", &k);
	while (k--) {
		int i, j, x, y;
		int sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (int k = i; k <= x; k++) {
			for (int l = j; l <= y; l++) {
				sum += arr[k][l];
			}
		}
		printf("%d\n", sum);
	}


	return 0;
}