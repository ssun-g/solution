#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq; // 보석의 가치순으로 내림차순 정렬
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > jewel; // 보석의 정보 저장 (무게가 가벼운 순으로 오름차순 정렬)
vector<int> bags; // 가방의 정보 저장 (무게가 가벼운 순으로 오름차순 정렬)

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) { // 보석 정보 입력
		int m, v;
		cin >> m >> v;
		jewel.push(make_pair(m, v));
	}

	for (int i = 0; i < K; i++) { // 가방 정보 입력
		int bag;
		cin >> bag;
		bags.push_back(bag);
	}
	sort(bags.begin(), bags.end());

	long long answer = 0;
	for (int i = 0; i < K; i++) {
		while (!jewel.empty() && jewel.top().first <= bags[i]) { // 현재 가방보다 보석이 가벼우면 우선순위큐에 넣어준다.
			pq.push(jewel.top().second);
			jewel.pop();
		}

		if (!pq.empty()) { // 우선순위큐에서 보석을 하나씩 꺼내서 가치를 더해준다.
			answer += pq.top();
			pq.pop();
		}

		else if (jewel.empty()) break; // 남은 보석이 없으면 종료
	}

	cout << answer << '\n';

	return 0;
}