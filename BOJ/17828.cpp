#include<bits/stdc++.h>
using namespace std;

int main() {
	string answer = "";
	int N, X;
	cin >> N >> X;
	if (N * 26 < X || X < N) cout << "!" << '\n';
	else {
		while (X) {
			int diff = 26 * N;
			if (diff - X < 26) {
				answer += (26 - (diff - X) - 1) + 'A';
				X -= (26 - (diff - X));
			}

			else {
				answer += 'A';
				X--;
			}
			N--;
		}
	}
	cout << answer << '\n';

	return 0;
}