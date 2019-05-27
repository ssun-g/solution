#include<cstdio>
#include<vector>
using namespace std;

int cover[4][3][2] = {
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{1,0}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
char board[21][21];
int wcnt;

int set(vector<vector<int> > &arr, int y, int x, int type, int cov) {
	int flag = 1;
	for (int i = 0; i < 3; i++) {
		int ny = y + cover[type][i][0];
		int nx = x + cover[type][i][1];
		if (ny < 0 || nx < 0 || ny >= arr.size() || nx >= arr[0].size()) flag = 0;
		else if ((arr[ny][nx] += cov) > 1) flag = 0;
	}
	return flag;
}

int coverTile(vector<vector<int> > &arr) {
	int y = -1, x = -1;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int t = 0; t < 4; t++) {
		if (set(arr, y, x, t, 1)) ret += coverTile(arr);
		set(arr, y, x, t, -1);
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int h, w;
		wcnt = 0;
		scanf("%d %d", &h, &w);
		vector<vector<int> > v(h, vector<int>(w, 0));
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				scanf(" %c", &board[j][k]);
				if (board[j][k] == '.') wcnt++;
				if (board[j][k] == '#') v[j][k] = 1;
			}
		}
		if (wcnt % 3 != 0) printf("0\n");
		else if (wcnt == 0) printf("1\n");
		else printf("%d\n", coverTile(v));
	}

	return 0;
}
