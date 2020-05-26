#include<cstdio>
#include<vector>
using namespace std;

vector<pair<int, int>> p;
char arr[250][250];
int r, c, sc, wc;
int check[250][250];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void go(int y, int x) {
	check[y][x] = 1;
	if (arr[y][x] == 'o') sc++;
	else if (arr[y][x] == 'v') wc++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < c && 0 <= ny && ny < r && !check[ny][nx] && arr[ny][nx] != '#')
			go(ny, nx);
	}

}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!check[i][j] && arr[i][j] != '#') {
				go(i, j);
				p.push_back(pair<int, int>(sc, wc));
				sc = 0;
				wc = 0;
			}
		}
	}

	for (int i = 0; i < p.size(); i++) {
		if (p[i].second < p[i].first) {
			p[i].second = 0;
			sc += p[i].first;
		}
		else {
			p[i].first = 0;
			wc += p[i].second;
		}
	}
	printf("%d %d\n", sc, wc);
	return 0;
}