#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int Map[26][26];
int check[26][26];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int y, int x, int size) {
	check[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < size && 0 <= ny && ny < size && !check[ny][nx] && Map[ny][nx] == 1)
			ret += dfs(ny, nx, size);
	}

	return ret;
}

int main() {
	vector<int> answer;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j] && Map[i][j] == 1)
				answer.push_back(dfs(i, j, N));
		}
	}

	int Size = answer.size();
	printf("%d\n", Size);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < Size; i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}