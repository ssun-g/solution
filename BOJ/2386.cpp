#include<bits/stdc++.h>
using namespace std;

string toLower(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}

	return s;
}

int main() {
	while (true) {
		char c;
		string s;
		cin >> c;
		getline(cin, s);

		if (c == '#') break;

		s = toLower(s); // 모두 소문자로 바꿔준다.
		int answer = 0;
		for (int i = 0; i < s.length(); i++) {
			if (c == s[i]) answer++; // 찾으려는 문자가 존재하면 카운트해준다.
		}

		cout << c << ' ' << answer << '\n';
	}


	return 0;
}