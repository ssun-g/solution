/*

각 마을에서 파티 장소로 이동하는 거리와 파티 장소에서 다시 자신의 마을로 돌아오는 거리가 다를 수 있다.
그래서 go, come 두 개의 vector로 갈 때, 올 때 최단 거리를 저장.
그 후, 각 학생들의 이동거리를 비교하면서 큰 값을 저장했다.

*/
#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, X;
vector<pair<int, int> > vp[1001];

vector<int> dijkstra(int start, int dest) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dist(N + 1, INF);
	bool visited[1001] = { false, }; // 노드의 방문 체크
	pq.push(make_pair(0, start)); // 시작 노드를 넣어준다. (비용, 노드)
	dist[start] = 0; // 시작 거리는 0

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue; // 이전에 방문했던 노드이면 pass

		visited[cur] = true;
		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i].first;
			int n_cost = vp[cur][i].second;
			if (dist[next] > cost + n_cost) { // next로 가기위한 비용이 원래의 비용보다 더 적다면 비용을 갱신한다.
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	return dist;
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		vp[u].push_back(make_pair(v, cost));
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		vector<int> go = dijkstra(i, X); // 각 학생(i)이 파티 장소(X)로 이동하는 최단거리
		vector<int> come = dijkstra(X, i); // 파티 장소(X)에서 각 학생들의 집(i)으로 돌아오는 최단 거리

		if (go[X] + come[i] >= INF) continue; // 이동 경로가 없는 경우.
		answer = max(answer, go[X] + come[i]);
	}

	cout << answer << '\n';

	return 0;
}