#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dist[20001];

void Memset() {
	for (int i = 0; i < 20001; i++) {
		dist[i] = -1;
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int MAX = -1;
	Memset();
	vector<vector<int> > v(n + 1);

	for (int i = 0; i < edge.size(); i++) {
		v[edge[i][0]].push_back(edge[i][1]);
		v[edge[i][1]].push_back(edge[i][0]);
	}

	queue<int> q;
	dist[1] = 0;
	for (int i = 0; i < v[1].size(); i++) {
		dist[v[1][i]] = dist[1] + 1;
		MAX = max(MAX, dist[v[1][i]]);
		q.push(v[1][i]);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (dist[v[cur][i]] == -1) {
				dist[v[cur][i]] = dist[cur] + 1;
				MAX = max(MAX, dist[v[cur][i]]);
				q.push(v[cur][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == MAX) answer++;
	}

	return answer;
}