#include<bits/stdc++.h>
using namespace std;

vector<char> answer;

int main() {
	int N, K;
	cin >> N >> K;

	for (int num_A = 0; num_A <= N; num_A++) {
		int num_B = N - num_A;
		if (num_A * num_B > K) { // K���� ũ�� a�� ������ �ϳ� ���� �־��ش�.
			for (int i = 0; i < num_A - 1; i++) answer.push_back('A');
			for (int i = 0; i < num_B; i++) answer.push_back('B');

			int left = K % num_B;
			answer[answer.size() - left] = 'A'; // �ϳ� ���� A�� �ڸ��� ã�� �ش�.
			answer.push_back('B');
		}
		else if (num_A * num_B == K) { // K�� ���ٸ� a, b�� ������ ������� �־��ش�.
			for (int i = 0; i < num_A; i++) answer.push_back('A');
			for (int i = 0; i < num_B; i++) answer.push_back('B');
		}
		else continue; // K���� ������ ���� �� ����.

		break;
	}

	if (answer.size() == 0) cout << -1 << '\n';
	else for (int i = 0; i < answer.size(); i++) cout << answer[i];

	return 0;
}