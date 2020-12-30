#include<bits/stdc++.h>
using namespace std;

int N, K, answer;
int put[100];
int schedule[100];

void Change(int init) {
	int change_idx, tmpidx = -1;
	for (int i = 0; i < N; i++) {
		int lastidx = 0;
		for (int j = init + 1; j < K; j++) {
			if (put[i] == schedule[j]) break;
			lastidx++;
		}

		if (lastidx > tmpidx) {
			change_idx = i;
			tmpidx = lastidx;
		}
	}
	answer++;
	put[change_idx] = schedule[init];
}

void solve() {
	for (int i = 0; i < K; i++) {
		bool usedFlug = false;
		for (int j = 0; j < N; j++) {
			if (put[j] == schedule[i]) {
				usedFlug = true;
				break;
			}
		}
		if (usedFlug) continue;

		for (int j = 0; j < N; j++) {
			if (put[j] == 0) {
				put[j] = schedule[i];
				usedFlug = true;
				break;
			}
		}
		if (usedFlug) continue;

		Change(i);
	}

	cout << answer << '\n';
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> schedule[i];
	}

	solve();

	return 0;
}