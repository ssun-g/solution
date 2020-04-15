#include<cstdio>
using namespace std;

int n, cnt;
int arr[16][16];
int check[16][16];

void go(int y, int x, int cs) {
	if (arr[y][x] == 1) return;
	if (y == n - 1 && x == n - 1) cnt++;
	if (!check[y][x] && y < n && x < n && arr[y][x] != 1) {
		check[y][x] = 1;
		if (cs == 1) {
			go(y, x + 1, 1);
			if (arr[y + 1][x + 1] == 0 && arr[y + 1][x] == 0 && arr[y][x + 1] == 0) go(y + 1, x + 1, 2);
		}
		else if (cs == 2) {
			go(y, x + 1, 1);
			if (arr[y + 1][x + 1] == 0 && arr[y + 1][x] == 0 && arr[y][x + 1] == 0) go(y + 1, x + 1, 2);
			go(y + 1, x, 3);
		}
		else {
			if (arr[y + 1][x + 1] == 0 && arr[y + 1][x] == 0 && arr[y][x + 1] == 0) go(y + 1, x + 1, 2);
			go(y + 1, x, 3);
		}
		check[y][x] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	go(0, 1, 1);
	printf("%d\n", cnt);

	return 0;
}