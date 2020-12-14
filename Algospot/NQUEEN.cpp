#include<bits/stdc++.h>
using namespace std;

int chess[12];
int answer;

bool comp(int n) {
	for (int i = 0; i < n; i++) {
		if (chess[n] == chess[i] || abs(chess[n] - chess[i]) == (n - i))
			return false;
	}

	return true;
}

void n_queen(int n, int size) {
	if (n == size) {
		answer++;
		return;
	}
	
	for (int i = 0; i < size; i++) {
		chess[n] = i;
		if (comp(n)) n_queen(n + 1, size);
	}
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		answer = 0;
		memset(chess, 0, sizeof(chess));

		int N;
		cin >> N;
		n_queen(0, N);
		cout << answer << '\n';
	}

	return 0;
}