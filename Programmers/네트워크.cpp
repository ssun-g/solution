#include <string>
#include <vector>

using namespace std;

int check[200];

void dfs(int n, vector<vector<int>> computers, int idx) {
	check[idx] = 1;
	for (int i = 0; i < n; i++) {
		if (!check[i] && computers[idx][i]) dfs(n, computers, i);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			answer++;
			dfs(n, computers, i);
		}
	}
	return answer;
}