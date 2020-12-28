#include<bits/stdc++.h>
using namespace std;

int pipe[1000];

int main() {
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> pipe[i];
	}
	sort(pipe, pipe + N);

	int cnt = 0;
	int cur = 0;
	for (int next = 0; next < N; next++) {
		if (pipe[next] - pipe[cur] + 1 > L) {
			cnt++;
			cur = next;
		}
	}
	cout << cnt + 1 << '\n';

	return 0;
}