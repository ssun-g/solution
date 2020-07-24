#include<cstdio>
#include<utility>
#include<queue>
using namespace std;

int n;
int dx, dy;
int chess[300][300];
int check[300][300];
int nx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int ny[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

void Reset() {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			chess[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		Reset();
		queue<pair<int, pair<int, int> > > q;
		pair<int, pair<int, int> > p;
		scanf("%d", &n);
		int x, y;
		scanf("%d %d", &x, &y);
		scanf("%d %d", &dx, &dy);

		q.push(make_pair(0, pair<int, int>(x, y)));
		check[y][x] = 1;

		while (!q.empty()) {
			p = q.front();
			int cnt = q.front().first;
			q.pop();
			if (p.second.first == dx && p.second.second == dy) {
				printf("%d\n", cnt);
				break;
			}
			for (int i = 0; i < 8; i++) {
				int next_x = p.second.first + nx[i];
				int next_y = p.second.second + ny[i];
				if (!check[next_y][next_x] && 0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
					q.push(make_pair(cnt + 1, pair<int, int>(next_x, next_y)));
					check[next_y][next_x] = 1;
				}
			}
		}
	}

	return 0;
}