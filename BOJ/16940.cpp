#include<bits/stdc++.h>
using namespace std;

int order[100001]; // � ��带 ���� �湮�ؾ� �ϴ���
int target[100001]; // �־��� bfs �湮 ����
bool isVisited[100001];
vector<int> vp[100001];
vector<int> seq;

// ��� �湮 �켱������ ���� �����ϱ� ���� ����
bool comp(int a, int b) {
	return order[a] < order[b];
}

// �ʺ�켱Ž��
void bfs(int start) {
	if (start != target[0]) return;

	queue<int> q;
	q.push(start);
	isVisited[start] = true;

	int idx = 1; // �� ��° node�� �湮�� �������� check
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i];
			if (!isVisited[next] && next == target[idx++]) { // �־��� Ž�� ������ ������ bfs ��� ����
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

	// � ��带 ���� �湮�ؾ� �ϴ��� ����.
	for (int i = 0; i < N; i++) {
		cin >> target[i];
		order[target[i]] = i + 1;
	}

	// �켱������ �°� ����
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