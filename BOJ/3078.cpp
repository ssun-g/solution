#include<iostream>
#include<string>
#include<queue>
using namespace std;

queue<int> q[21];

long long good_friend(int N, int K) {
	long long answer = 0;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;

		int len = s.length();
		while (!q[len].empty() && i - q[len].front() > K) {
			q[len].pop();
		}
		answer += q[len].size();
		q[len].push(i);

	}

	return answer;
}

int main() {
	int answer = 0;
	int N, K;
	cin >> N >> K;
	cout << good_friend(N, K) << '\n';

	return 0;
}