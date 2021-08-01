#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	string from, to;
	cin >> from >> to;

	// 1번 스위치를 누른 경우
	string init1 = from;
	init1[0] = (init1[0] == '0') ? '1' : '0';
	init1[1] = (init1[1] == '0') ? '1' : '0';
	int cnt1 = 1;
	for (int i = 1; i < N; i++) {
		if (init1[i - 1] != to[i - 1]) {
			cnt1++;
			init1[i - 1] = (init1[i - 1] == '0') ? '1' : '0';
			init1[i] = (init1[i] == '0') ? '1' : '0';
			if (i != N - 1) init1[i + 1] = (init1[i + 1] == '0') ? '1' : '0';
		}
	}
	if (init1 != to) cnt1 = 987654321;

	// 1번 스위치를 누르지 않은 경우
	string init2 = from;
	int cnt2 = 0;
	for (int i = 1; i < N; i++) {
		if (init2[i - 1] != to[i - 1]) {
			cnt2++;
			init2[i - 1] = (init2[i - 1] == '0') ? '1' : '0';
			init2[i] = (init2[i] == '0') ? '1' : '0';
			if (i != N - 1) init2[i + 1] = (init2[i + 1] == '0') ? '1' : '0';
		}
	}
	if (init2 != to) cnt2 = 987654321;

	int answer = min(cnt1, cnt2);
	(answer == 987654321) ? cout << -1 << '\n' : cout << answer << '\n';

	return 0;
}