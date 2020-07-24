#include<cstdio>
#include<utility>
#include<functional>
#include<vector>
#include<queue>

#define INF 987654321
using namespace std;

int V, E, start, u, v, w;
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > vec[20001];

void dijkstra() {
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int n_cost = vec[cur][i].second;
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &start);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		vec[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) dist[i] = INF;

	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}