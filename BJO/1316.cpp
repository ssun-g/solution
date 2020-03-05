#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int alpha[26];

bool check(string str) {
	for (int i = 0; i < 26; i++) alpha[i] = 0;
	for (int i = 0; i < str.length(); i++) {
		if (alpha[(int)(str[i] - 'a')]) return false;
		
		char cur = str[i];
		alpha[(int)(cur - 'a')] = 1;

		while (true) {
			if (cur != str[++i]) {
				--i;
				break;
			}
		}
	}
	return true;
}

int main() {
	int tc;
	int cnt = 0;
	string s;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		cin >> s;
		if (check(s)) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}