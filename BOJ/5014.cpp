#include<iostream>
#include<queue>
using namespace std;

int height, from, to, up, down;
int check[1000001];

void bfs() {
	queue<int> q;
	q.push(from);
	check[from] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == to) {
			return;
		}

		int next = cur + up;
		if (next <= height && !check[next]) {
			check[next] = check[cur] + 1;
			q.push(next);
		}

		next = cur - down;
		if (next >= 1 && !check[next]) {
			check[next] = check[cur] + 1;
			q.push(next);
		}
	}
}

int main() {
	cin >> height >> from >> to >> up >> down;

	bfs();

	if (check[to] != 0) cout << check[to] - 1 << '\n';
	else cout << "use the stairs" << '\n';

	return 0;
}