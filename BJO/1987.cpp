#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;

int Max, r, c;
int check[26];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
char arr[20][20];

void dfs(int, int, int);

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("\n%c", &arr[i][j]);
		}
	}
	check[(int)arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	printf("%d\n", Max);

	return 0;
}

void dfs(int row, int col, int cnt) {
	Max = max(Max, cnt);
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (0 <= nr && nr < r && 0 <= nc && nc < c && !check[(int)arr[nr][nc] - 'A']) {
			check[(int)arr[nr][nc] - 'A'] = 1;
			dfs(nr, nc, cnt + 1);
			check[(int)arr[nr][nc] - 'A'] = 0;
		}
	}
}