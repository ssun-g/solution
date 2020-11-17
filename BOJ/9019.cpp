#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

int check[10001];

void Reset() {
	for (int i = 0; i <= 10000; i++) {
		check[i] = 0;
	}
}

void bfs(int from, int to) {
	queue<pair<int, string> > qp;
	qp.push(make_pair(from, ""));
	check[from] = 1;

	while (!qp.empty()) {
		int cur = qp.front().first;
		string order = qp.front().second;
		qp.pop();

		if (cur == to) {
			cout << order << '\n';
			return;
		}

		int next = (2 * cur) % 10000;
		if (!check[next]) {
			check[next] = 1;
			qp.push(make_pair(next, order + "D"));
		}
		next = (cur == 0) ? 9999 : cur - 1;
		if (!check[next]) {
			check[next] = 1;
			qp.push(make_pair(next, order + "S"));
		}

		next = (cur % 1000) * 10 + (cur / 1000);
		if (!check[next]) {
			check[next] = 1;
			qp.push(make_pair(next, order + "L"));
		}

		next = (cur % 10) * 1000 + (cur / 10);
		if (!check[next]) {
			check[next] = 1;
			qp.push(make_pair(next, order + "R"));
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int from, to;
		cin >> from >> to;

		bfs(from, to);
		Reset();
	}

	return 0;
}