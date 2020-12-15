#include<bits/stdc++.h>
using namespace std;

int n;
int board[100][100];
int cache[100][100];

int jumpGame(int y, int x) {
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	int size = board[y][x];
	ret = (jumpGame(y + size, x) || jumpGame(y, x + size));

	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(board, 0, sizeof(board));
		memset(cache, -1, sizeof(cache));

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (jumpGame(0, 0) == 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}