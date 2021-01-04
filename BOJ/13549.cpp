// priority_queue를 이용해 풀어야 할 것 같은데 일단 AC를 받았다.
// 나중에 틀리면 다시 풀어 봐야 겠다.
#include<bits/stdc++.h>
using namespace std;

int dist[100001];

int bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == end) return dist[cur];

		// 2*X 순간이동은 0초이기 때문에 먼저 계산해주어야 한다.
		if (2 * cur <= 100000 && dist[2 * cur] == -1) {
			q.push(2 * cur);
			dist[2 * cur] = dist[cur];
		}

		if (0 <= cur - 1 && dist[cur - 1] == -1) {
			q.push(cur - 1);
			dist[cur - 1] = dist[cur] + 1;
		}
		if (cur + 1 <= 100000 && dist[cur + 1] == -1) {
			q.push(cur + 1);
			dist[cur + 1] = dist[cur] + 1;
		}

	}
}

int main() {
	int N, K;
	cin >> N >> K;
	memset(dist, -1, sizeof(dist));

	cout << bfs(N, K) << '\n';

	return 0;
}