#include<bits/stdc++.h>
using namespace std;

int cnt;
int N, r, c;

bool dnc(int y, int x, int size) {
	if (size == 1) {
		if (y == r && x == c) {
			printf("%d\n", cnt);
			return true;
		}
		cnt++;
		return false;
	}

	if (!(y <= r && r < y + size && x <= c && c < x + size)) {
		cnt += size*size;
		return false;
	}

	if (dnc(y, x, size / 2)) return true;
	if (dnc(y, x + size / 2, size / 2)) return true;
	if (dnc(y + size / 2, x, size / 2)) return true;
	if (dnc(y + size / 2, x + size / 2, size / 2)) return true;

	return false;
}

int main() {
	cin >> N >> r >> c;

	dnc(0, 0, pow(2, N));

	return 0;
}