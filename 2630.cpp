#include<cstdio>
using namespace std;

int arr[129][129], wcnt, bcnt;
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
	printf("%d\n%d", wcnt, bcnt);
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

	if (flag && temp == 0) {
		wcnt++;
		return;
	}
	else if (flag && temp == 1) {
		bcnt++;
		return;
	}

	go(x, y, size / 2);
	go(x, y + (size / 2), size / 2);
	go(x + (size / 2), y, size / 2);
	go(x + (size / 2), y + (size / 2), size / 2);
}