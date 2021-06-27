#include<bits/stdc++.h>

#define INF 987654321
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > vp[1001]; // (이어진 노드, 거리) 쌍
int dist[1001];
bool visited[1001];

void dijkstra(int start) {
	pq.push(make_pair(0, start)); // 시작점을 우선순위 큐에 삽입
	dist[start] = 0; // 시작점의 거리를 0으로 초기화

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue; // 이미 방문한 정점이면 pass

		visited[cur] = true;
		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i].first;
			int n_cost = vp[cur][i].second;
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}

	}
}

int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		vp[u].push_back(make_pair(v, cost));
	}

	for (int i = 1; i <= N; i++) dist[i] = INF; // 나올 수 없는 큰 값을 넣어준다.

	int start, end;
	cin >> start >> end;
	dijkstra(start);
	cout << dist[end] << '\n';

	return 0;
}