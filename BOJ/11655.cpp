#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			if ('z' < s[i] + 13) printf("%c", s[i] + 13 - 26);
			else printf("%c", s[i] + 13);
		}
		else if ('A' <= s[i] && s[i] <= 'Z') {
			if ('Z' < s[i] + 13) printf("%c", s[i] + 13 - 26);
			else printf("%c", s[i] + 13);
		}
		else cout << s[i];
	}

	return 0;
}