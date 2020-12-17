#include<bits/stdc++.h>
using namespace std;

bool isFA(string s) {
	int tmp = (s[0] - '0') * s.length();
	s = to_string(tmp);
	for (int i = 0; i < 100; i++) {
		int f = s[0] - '0';
		int len = s.length();
		
		if (tmp == f*len) return true;
		tmp = f*len;
	}

	return false;
}

int main() {
	string s;
	cin >> s;

	if (isFA(s)) cout << "FA" << '\n';
	else cout << "NFA" << '\n';
	
	return 0;
}