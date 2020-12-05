#include<bits/stdc++.h>
using namespace std;

int Ratio(long long game, long long win) {
	return (win * 100) / game;
}

void needs(long long game, long long win) {
	long long left = 0, right = 2000000000;
	int rates = Ratio(game, win);
	if (rates == Ratio(game+right, win+right)) {
		cout << -1 << '\n';
		return;
	}

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (rates == Ratio(game + mid, win + mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	cout << left << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long N, M;
		cin >> N >> M;
		needs(N, M);
	}

	return 0;
}