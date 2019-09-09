#include<cstdio>
using namespace std;

int arr[2188][2188], mcnt, zcnt, cnt;
void go(int, int, int);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	go(0, 0, n);
	printf("%d\n%d\n%d", mcnt, zcnt, cnt);

	return 0;
}

void go(int x, int y, int size) {
	int temp = arr[x][y];
	bool flag = true;

	for (int i = x; i < x + size; i++) {
		if (!flag)
			break;
		for (int j = y; j < y + size; j++) {
			if (temp != arr[i][j]) {
				flag = false;
				break;
			}
		}
	}

	if (flag && temp == -1) {
		mcnt++;
		return;
	}
	else if (flag && temp == 0) {
		zcnt++;
		return;
	}
	else if (flag && temp == 1) {
		cnt++;
		return;
	}

	go(x, y, size / 3);
	go(x, y + (size / 3), size / 3);
	go(x, y + (2 * (size / 3)), size / 3);
	go(x + (size / 3), y, size / 3);
	go(x + (size / 3), y + (size / 3), size / 3);
	go(x + (size / 3), y + (2 * (size / 3)), size / 3);
	go(x + (2 * (size / 3)), y, size / 3);
	go(x + (2 * (size / 3)), y + (size / 3), size / 3);
	go(x + (2 * (size / 3)), y + (2 * (size / 3)), size / 3);
}