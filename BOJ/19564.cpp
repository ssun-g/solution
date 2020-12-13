#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int ret = 1;
	char c = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (c >= s[i]) ret++;
		c = s[i];
	}

	return ret;
}

int main() {
	string s;
	cin >> s;
	cout << solve(s) << '\n';

	return 0;
}