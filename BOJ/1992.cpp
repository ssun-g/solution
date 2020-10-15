#include<cstdio>
using namespace std;

int quad[65][65];

void dnc(int y, int x, int size) {
	int temp = quad[y][x];
	bool isEqual = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (temp != quad[i][j]) {
				isEqual = false;
				break;
			}
		}
		if (!isEqual) break;
	}

	if (isEqual) {
		printf("%d", temp);
		return;
	}

	printf("(");
	dnc(y, x, size / 2);
	dnc(y, x + size / 2, size / 2);
	dnc(y + size / 2, x, size / 2);
	dnc(y + size / 2, x + size / 2, size / 2);
	printf(")");
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &quad[i][j]);
		}
	}
	dnc(0, 0, N);

	return 0;
}