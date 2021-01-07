// 문제 조건 제대로 읽기! (소문자로 출력)
#include<bits/stdc++.h>
using namespace std;

int main() {
	string answer = "";
	int len = 0;
	while (true) {
		string s;
		cin >> s;
		if (s == "E-N-D") break;

		string tmp = "";
		for (int i = 0; i < s.length(); i++) {
			if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || s[i] == '-')
				tmp += s[i];
		}

		if (len < tmp.length()) {
			len = tmp.length();
			answer = tmp;
		}

	}
	
	for (int i = 0; i < answer.length(); i++) {
		answer[i] = tolower(answer[i]);
	}
	cout << answer << '\n';

	return 0;
}