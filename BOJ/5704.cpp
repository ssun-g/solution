#include<iostream>
#include<string>
using namespace std;

int alpha[26];

void Reset() {
	for (int i = 0; i < 26; i++) {
		alpha[i] = 0;
	}
}

int Check() {
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) return 0;
	}

	return 1;
}

int main() {
	string s;
	while (true) {
		Reset();
		getline(cin, s);
		if (s == "*") break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') continue;
			alpha[(int)(s[i] - 'a')]++;
		}
		if (Check()) cout << 'Y' << '\n';
		else cout << 'N' << '\n';
	}

	return 0;
}