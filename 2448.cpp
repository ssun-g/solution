#include<cstdio>
using namespace std;

void go(int, int, int);
char arr[3073][6145];

int main() {
	int n;
	scanf("%d", &n);

	go(0, n - 1, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void go(int x, int y, int h) {
	if (h == 3) {
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		arr[x + 2][y - 2] = '*';
		arr[x + 2][y - 1] = '*';
		arr[x + 2][y] = '*';
		arr[x + 2][y + 1] = '*';
		arr[x + 2][y + 2] = '*';
		return;
	}

	go(x, y, h / 2);
	go(x + (h / 2), y - (h / 2), h / 2);
	go(x + (h / 2), y + (h / 2), h / 2);
}