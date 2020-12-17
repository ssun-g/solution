#include<bits/stdc++.h>
using namespace std;

int GCD(string a, string b) {
	int n = stoi(a);
	int m = stoi(b);
	if (m == 0) return n;
	return GCD(to_string(m), to_string(n%m));
}

int main() {
	string s;
	cin >> s;

	int idx;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ':') idx = i;
	}

	string n = s.substr(0, idx);
	string m = s.substr(idx + 1);
	int g = GCD(n, m);

	cout << stoi(n) / g << ':' << stoi(m) / g << '\n';

	return 0;
}