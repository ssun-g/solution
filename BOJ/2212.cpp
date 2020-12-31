#include<bits/stdc++.h>
using namespace std;

int N, K;
int sensor[10000];
priority_queue<int, vector<int> > pq;

int solve() {
	int ret = 0;
	for (int i = 1; i < N; i++) {
		pq.push(sensor[i] - sensor[i - 1]);
	}

	int cnt = 1;
	while (!pq.empty()) {
		if (cnt < K) {
			cnt++;
			pq.pop();
			continue;
		}
		ret += pq.top();
		pq.pop();
	}

	return ret;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> sensor[i];
	}
	sort(sensor, sensor + N);

	if (N <= K) cout << 0 << '\n';
	else cout << solve() << '\n';

	return 0;
}