#include<bits/stdc++.h>
using namespace std;

vector<char> answer;

int main() {
	int N, K;
	cin >> N >> K;

	for (int num_A = 0; num_A <= N; num_A++) {
		int num_B = N - num_A;
		if (num_A * num_B > K) { // K보다 크면 a의 개수를 하나 적게 넣어준다.
			for (int i = 0; i < num_A - 1; i++) answer.push_back('A');
			for (int i = 0; i < num_B; i++) answer.push_back('B');

			int left = K % num_B;
			answer[answer.size() - left] = 'A'; // 하나 남은 A의 자리를 찾아 준다.
			answer.push_back('B');
		}
		else if (num_A * num_B == K) { // K와 같다면 a, b의 개수를 순서대로 넣어준다.
			for (int i = 0; i < num_A; i++) answer.push_back('A');
			for (int i = 0; i < num_B; i++) answer.push_back('B');
		}
		else continue; // K보다 작으면 만들 수 없다.

		break;
	}

	if (answer.size() == 0) cout << -1 << '\n';
	else for (int i = 0; i < answer.size(); i++) cout << answer[i];

	return 0;
}