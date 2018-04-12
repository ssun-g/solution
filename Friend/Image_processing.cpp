#include<cstdio>
using namespace std;

int arr[256][256];
int b_cnt, w_cnt;
void go(int, int, int);

int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		go(0, 0, n);
		printf("%d %d\n", w_cnt, b_cnt);
		w_cnt = 0;
		b_cnt = 0;
	}

	return 0;
}

void go(int x, int y, int size) {
	int temp = arr[x][y];
	bool flag = true;
	for (int i = x; i < x + size; i++) {
		if (!flag) break;
		for (int j = y; j < y + size; j++) {
			if (temp != arr[i][j]) {
				flag = false;
				break;
			}
		}
	}
	if (flag && temp) {
		b_cnt++;
		return;
	}
	if (flag && !temp) {
		w_cnt++;
		return;
	}

	go(x, y, size / 2);
	go(x, y + (size / 2), size / 2);
	go(x + (size / 2), y, size / 2);
	go(x + (size / 2), y + (size / 2), size / 2);
}