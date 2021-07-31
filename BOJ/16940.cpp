#include<bits/stdc++.h>
using namespace std;

int order[100001]; // 어떤 노드를 먼저 방문해야 하는지
int target[100001]; // 주어진 bfs 방문 순서
bool isVisited[100001];
vector<int> vp[100001];
vector<int> seq;

// 노드 방문 우선순위에 따라 정렬하기 위한 조건
bool comp(int a, int b) {
	return order[a] < order[b];
}

// 너비우선탐색
void bfs(int start) {
	if (start != target[0]) return;

	queue<int> q;
	q.push(start);
	isVisited[start] = true;

	int idx = 1; // 몇 번째 node를 방문할 차례인지 check
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i];
			if (!isVisited[next] && next == target[idx++]) { // 주어진 탐색 순서와 같으면 bfs 계속 진행
				isVisited[next] = true;
				q.push(next);
				seq.push_back(next);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		vp[u].push_back(v);
		vp[v].push_back(u);
	}

	// 어떤 노드를 먼저 방문해야 하는지 저장.
	for (int i = 0; i < N; i++) {
		cin >> target[i];
		order[target[i]] = i + 1;
	}

	// 우선순위에 맞게 정렬
	for (int i = 1; i <= N; i++) {
		sort(vp[i].begin(), vp[i].end(), comp);
	}

	seq.push_back(target[0]);
	bfs(1);

	for (int i = 0; i < N; i++) {
		if (seq.size() <= i || seq[i] != target[i]) {
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;
}