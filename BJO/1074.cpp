#include<cstdio>
#include<cmath>
using namespace std;

int cnt, n, r, c;
void go(int, int, int);

int main() {
	scanf("%d%d%d", &n, &r, &c);

	go(0, 0, pow(2, n));
	return 0;
}

void go(int x, int y, int size) {
	if (size == 2) {
		if (x == r && y == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (x == r && y + 1 == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (x + 1 == r && y == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (x + 1 == r && y + 1 == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		return;
	}

	go(x, y, size / 2);
	go(x, y + (size / 2), size / 2);
	go(x + (size / 2), y, size / 2);
	go(x + (size / 2), y + (size / 2), size / 2);
}