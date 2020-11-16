#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

bool primeNum[10000];
int check[10000];

void Reset() {
	for (int i = 0; i < 10000; i++) {
		check[i] = 0;
	}
}

void Eratos() {
	for (int i = 0; i < 10000; i++) primeNum[i] = true;
	for (int i = 2; i*i < 10000; i++) {
		if (primeNum[i]) {
			for (int j = i*i; j < 10000; j += i) {
				primeNum[j] = false;
			}
		}
	}
}

void Convert(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			string f = to_string(cur);
			for (int j = 0; j < 10; j++) {
				f[i] = j + '0';
				int next = stoi(f);
				if (1000 <= next && next <= 9999 && primeNum[next] && !check[next]) {
					check[next] = check[cur] + 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	Eratos();

	int tc;
	cin >> tc;
	while (tc--) {
		int from, to;
		cin >> from >> to;

		Convert(from);

		if (check[to] != 0) cout << check[to] - 1 << '\n';
		else cout << "Impossible" << '\n';

		Reset();
	}

	return 0;
}