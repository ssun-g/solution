#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int Min = 987654321;
int R, C, minX, minY;
int arr[1001][1001];

string route(int Case) {
	string ret = "";
	// row is odd
	if (Case == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0) ret += 'R';
				else ret += 'L';
			}
			if (i != R - 1) ret += 'D';
		}
	}

	// column is odd
	else if (Case == 2) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R - 1; j++) {
				if (i % 2 == 0) ret += 'D';
				else ret += 'U';
			}
			if (i != C - 1) ret += 'R';
		}
	}

	// both even
	else {
		int sx = 0, sy = 0;
		int  ex = C - 1, ey = R - 1;
		string rev = "";

		while (ey - sy > 1) {
			// start from (0, 0)
			if (sy / 2 < minY / 2) {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < C - 1; j++) {
						if (i % 2 == 0) ret += 'R';
						else ret += 'L';
					}
					ret += 'D';
				}
				sy += 2;
			}

			// start from (r, c)
			if (minY / 2 < ey / 2) {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < C - 1; j++) {
						if (i % 2 == 0) rev += 'R';
						else rev += 'L';
					}
					rev += 'D';
				}
				ey -= 2;
			}
		}

		while (ex - sx > 1) {
			// start from (0, 0)
			if (sx / 2 < minX / 2) {
				ret += "DRUR";
				sx += 2;
			}

			// start from (r, c)
			if (minX / 2 < ex / 2) {
				rev += "DRUR";
				ex -= 2;
			}
		}

		if (minX == sx) ret += "RD";
		else ret += "DR";

		reverse(rev.begin(), rev.end());
		ret += rev;
	}

	return ret;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &arr[i][j]);
			if ((i + j) % 2 == 1 && arr[i][j] < Min) {
				Min = arr[i][j];
				minY = i;
				minX = j;
			}
		}
	}

	if (R % 2 == 1) cout << route(1) << '\n';
	else if (C % 2 == 1) cout << route(2) << '\n';
	else if (R % 2 == 0 && C % 2 == 0) cout << route(3) << '\n';

	return 0;
}