#include<cstdio>
#include<algorithm>
using namespace std;

int arr[500][500];

int main() {
	int n;
	int MAX = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) arr[i][j] = arr[i - 1][0] + arr[i][j];
			else if (j == i) arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
			else arr[i][j] = max(arr[i][j] + arr[i - 1][j - 1], arr[i][j] + arr[i - 1][j]);

			MAX = max(MAX, arr[i][j]);
		}
	}
	printf("%d\n", MAX);

	return 0;
}