#include<bits/stdc++.h>
using namespace std;

string club[9] = {
	"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT",
	"MOTION", "SPG", "COMON", "ALMIGHTY"
};

int main() {
	int N;
	int MAX = -1;
	string answer = "";
	cin >> N;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < N; j++) {
			int sol;
			cin >> sol;
			if (MAX < sol) {
				MAX = sol;
				answer = club[i];
			}
		}
	}
	cout << answer << '\n';

	return 0;
}