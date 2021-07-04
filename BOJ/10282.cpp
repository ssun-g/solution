#include<bits/stdc++.h>
using namespace std;

void dijkstra(int n, int d, int c) {
	// test case마다 초기화 해주어야 하므로 함수 내에서 선언
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<vector<pair<int, int> > > vp(n + 1);
	vector<int> dist(n + 1, INT_MAX);

	for (int i = 0; i < n + 1; i++) dist[i] = INT_MAX; // 초기 값은 최대값으로 넣어준다.

	for (int i = 0; i < d; i++) { // 컴퓨터의 의존성을 나타내는 그래프
		int a, b, s;
		scanf("%d %d %d", &a, &b, &s);
		vp[b].push_back(make_pair(a, s));
	}

	// 시작점은 의존성(비용)이 0이다. 
	pq.push(make_pair(0, c));
	dist[c] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue; // 이미 방문한 노드이면 넘어간다.

		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i].first;
			int n_cost = vp[cur][i].second;
			if (dist[next] > cost + n_cost) { // 비용이 더 적다면 새로 갱신해준다.
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	int cnt = 0;
	int max_dist = -1;
	for (int i = 1; i <= n; i++) {
		// dist가 갱신된 적이 있으면 (INT_MAX가 아니면) 감염된 컴퓨터, 그중 최대값이 마지막 컴퓨터가 감염된 시간 
		if (dist[i] != INT_MAX) {
			max_dist = max(max_dist, dist[i]);
			cnt++;
		}
	}

	printf("%d %d\n", cnt, max_dist);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, d, c;
		scanf("%d %d %d", &n, &d, &c);
		dijkstra(n, d, c);
	}

	return 0;
}