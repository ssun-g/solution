#include<bits/stdc++.h>
using namespace std;

// dp[a][b][c] = d
// (a, b)에 존재하는 알파벳을 찾으려는 문자열의 'c'번째 인덱스로 설정했을 때
// d개의 문자열을 찾을 수 있다.
int N, M, K;
string rows, target;

int dp[100][100][80];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<string> Map;

int dfs(int y, int x, int idx) {
	if (dp[y][x][idx] != -1) return dp[y][x][idx];
	if (idx == target.length()) return 1;

	dp[y][x][idx] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= K; j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if (0 <= nx && nx < M && 0 <= ny && ny < N && Map[ny][nx] == target[idx])
				dp[y][x][idx] += dfs(ny, nx, idx + 1);
		}
	}

	return dp[y][x][idx];
}

int main() {
	int answer = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> rows;
		Map.push_back(rows);
	}
	cin >> target;

	memset(dp, -1, sizeof(dp));

	char tmp = target[0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == tmp) answer += dfs(i, j, 1);
		}
	}
	cout << answer << '\n';

	return 0;
}