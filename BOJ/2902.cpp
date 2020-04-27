#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	string answer = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') answer += s[i];
	}
	cout << answer << '\n';

	return 0;
}