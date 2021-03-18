#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int dist[50001]; // 시작 node로 부터 i번째 노드까지의 최단 거리
bool visited[50001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 비용이 작은 경로를 우선 탐색하기 위한 우선순위 큐
vector<pair<int, int> > vp[50001]; // 노드의 연결을 표현하기 위함 (연결된 노드, 비용) 쌍

void dijkstra(int start, int end) {
	pq.push(make_pair(0, start)); // 시작 지점의 비용(거리), 노드를 저장 해준다.
	dist[start] = 0; // 시작 지점으로부터의 거리는 당연히 0이다.

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_node == end) return; // 목표 지점에 도착 했으면 더 이상 진행하지 않는다.
		if (visited[cur_node]) continue; // 이미 방문한 노드이면 pass한다.

		visited[cur_node] = true;
		for (int i = 0; i < vp[cur_node].size(); i++) {
			int next = vp[cur_node][i].first;
			int n_cost = vp[cur_node][i].second;

			// 방문할 노드의 거리가 (현재까지의 cost + 다음 노드로 이동할 때의 cost)보다 크다면 새로 갱신해주며 이동.
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		vp[u].push_back(make_pair(v, cost)); // 양 방향으로 노드를 연결해준다.
		vp[v].push_back(make_pair(u, cost));
	}

	for (int i = 1; i <= N; i++) dist[i] = INF; // 나올 수 없는 큰 값을 비용에 넣어준다. (최소한의 비용으로 갱신하기 위함)

	dijkstra(1, N);
	cout << dist[N] << '\n';

	return 0;
}