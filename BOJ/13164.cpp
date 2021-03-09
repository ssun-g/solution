#include<bits/stdc++.h>
using namespace std;

int group[300000];
priority_queue<int> pq;

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> group[i];
	}

	// 우선 순위 큐를 이용해 조가 될 수 있는 경우의 수 마다의 비용을 저장해준다.
	for (int i = 1; i < N; i++) {
		pq.push(group[i] - group[i - 1]);
	}

	long long answer = 0;
	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();

		if (K > 1) K--; // K-1번 조를 나눠준다. (K개의 조가 만들어진다)
		else answer += top; // 조를 나눈 후 남은 비용들을 더해주면 조별 비용이 된다.
	}
	cout << answer << '\n';

	return 0;
}
