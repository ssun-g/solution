#include<cstdio>
using namespace std;

char arr[6200][6200];

void star(int y, int x, int n) {
	if (n == 0) return;
	if (n % 3 == 0) {
		arr[y][x] = '*';
		arr[y][x + 1] = '*';
		arr[y][x + 2] = '*';
		arr[y + 1][x] = '*';
		arr[y + 1][x + 2] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
	}

	star(y, x, n / 3);
	star(y, x + n / 3, n / 3);
	star(y, x + (2 * n / 3), n / 3);
	star(y + n / 3, x, n / 3);
	star(y + n / 3, x + (2 * n / 3), n / 3);
	star(y + (2 * n / 3), x, n / 3);
	star(y + (2 * n / 3), x + n / 3, n / 3);
	star(y + (2 * n / 3), x + (2 * n / 3), n / 3);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = ' ';
		}
	}

	star(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}