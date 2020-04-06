#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int cnt;
int X;
int ladder[100][100];
int check[100][100];
int dx[3] = { -1, 1, 0 };
int dy[3] = { 0, 0, -1 };

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a > b;
	return a.first < b.first;
}

void Reset() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			check[i][j] = 0;
		}
	}
}

void dfs(int y, int x) {
	check[y][x] = 1;
	if (y == 0) X = x;
	for (int i = 0; i < 3; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (ladder[cy][cx] == 1 && cy < 100 && cx < 100 && cy >= 0 && cx >= 0 && !check[cy][cx]) {
			cnt++;
			dfs(cy, cx);
			return;
		}
	}
}

int main() {
	int num;
	for (int tc = 0; tc < 10; tc++) {
		scanf("%d", &num);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &ladder[i][j]);
			}
		}

		for (int j = 0; j < 100; j++) {
			if (ladder[99][j] == 1) {
				cnt = 1;
				Reset();
				dfs(99, j);
				v.push_back(pair<int, int>(cnt, X));
			}
		}
		sort(v.begin(), v.end(), comp);
		printf("#%d %d\n", num, v[0].second);
		v.clear();
	}

	return 0;
}