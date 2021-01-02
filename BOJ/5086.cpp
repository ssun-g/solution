#include<bits/stdc++.h>
using namespace std;

string solve(int n, int m) {
	if (m % n == 0) return "factor";
	else if (n%m == 0) return "multiple";
	else return "neither";
}

int main() {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		else cout << solve(n, m) << '\n';
	}

	return 0;
}