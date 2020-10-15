#include<cstdio>
using namespace std;

int ncnt, zcnt, pcnt;
int arr[2188][2188];

void dnc(int y, int x, int size) {
	int temp = arr[y][x];
	bool isEqual = true;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (temp != arr[i][j]) {
				isEqual = false;
				break;
			}
		}
		if (!isEqual) break;
	}

	if (isEqual && temp == -1) {
		ncnt++;
		return;
	}
	else if (isEqual && temp == 0) {
		zcnt++;
		return;
	}
	else if (isEqual && temp == 1) {
		pcnt++;
		return;
	}

	dnc(y, x, size / 3);
	dnc(y, x + size / 3, size / 3);
	dnc(y, x + 2 * (size / 3), size / 3);
	dnc(y + size / 3, x, size / 3);
	dnc(y + size / 3, x + size / 3, size / 3);
	dnc(y + size / 3, x + 2 * (size / 3), size / 3);
	dnc(y + 2 * (size / 3), x, size / 3);
	dnc(y + 2 * (size / 3), x + size / 3, size / 3);
	dnc(y + 2 * (size / 3), x + 2 * (size / 3), size / 3);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dnc(0, 0, n);

	printf("%d\n", ncnt);
	printf("%d\n", zcnt);
	printf("%d\n", pcnt);

	return 0;
}