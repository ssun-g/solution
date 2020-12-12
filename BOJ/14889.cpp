#include<bits/stdc++.h>
using namespace std;

int result = 987654321;
int stats[20][20];
int check[20];
int team_start[10];
int team_link[10];

void dfs(int init, int cnt, int size) {
	if (cnt == size / 2) {
		int idx = 0;
		int sum_start = 0;
		int sum_link = 0;
		for (int i = 0; i < size; i++) {
			if (!check[i]) team_link[idx++] = i;
		}

		for (int i = 0; i < size / 2; i++) {
			for (int j = 0; j < size; j++) {
				if (team_start[i] != j && check[j])
					sum_start += stats[team_start[i]][j];

				if (team_link[i] != j && !check[j])
					sum_link += stats[team_link[i]][j];
			}
		}
		result = min(result, abs(sum_start - sum_link));

		return;
	}

	for (int i = init; i < size; i++) {
		if (!check[i]) {
			check[i] = 1;
			team_start[cnt] = i;
			dfs(i + 1, cnt + 1, size);
			check[i] = 0;
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> stats[i][j];
		}
	}
	dfs(0, 0, N);
	cout << result << '\n';

	return 0;
}