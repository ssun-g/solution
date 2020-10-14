#include<cstdio>
using namespace std;

int arr[3073][6145];

void star(int y, int x, int n) {
	if (n == 0) return;
	if (n % 3 == 0) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
	}

	star(y, x, n / 2);
	star(y + n / 2, x - n / 2, n / 2);
	star(y + n / 2, x + n / 2, n / 2);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			arr[i][j] = ' ';
		}
	}

	star(0, n - 1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}