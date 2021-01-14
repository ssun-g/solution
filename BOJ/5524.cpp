#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
	string ret = "";
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') ret += tolower(s[i]);
		else ret += s[i];
	}

	return ret;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		cout << solve(s) << '\n';
	}

	return 0;
}