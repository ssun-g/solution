#include <bits/stdc++.h>
using namespace std;

pair<int, int> Solve(int len, const vector<int>& ants) {
	int fast_time = 0; // 모든 개미에 대한 최단 시간 중 가장 큰 값
	int late_time = 0; // 모든 개미에 대한 최장 시간 중 가장 큰 값
	for (int i = 0; i < ants.size(); i++) { // 각각의 개미에 대해 최단, 최장시간을 구해준다.
		fast_time = max(fast_time, min(abs(len - ants[i]), ants[i]));
		late_time = max(late_time, max(abs(len - ants[i]), ants[i]));
	}

	return make_pair(fast_time, late_time);
}

int main() {
	int tc;
	cin >> tc; // test case 입력
	while (tc--) {
		int len, num_of_ants;
		cin >> len >> num_of_ants; // 막대의 길이와 개미의 수 입력

		vector<int> ants;
		for (int i = 0; i < num_of_ants; i++) { // 개미의 위치 입력
			int loc;
			cin >> loc;
			ants.push_back(loc);
		}
		pair<int, int> answer = Solve(len, ants);

		cout << answer.first << ' ' << answer.second << '\n';
	}

	return 0;
}