#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int palin(string s) {
	int l = 0;
	int r = s.length() - 1;
	while (l < r) {
		if (s[l] != s[r]) return 0;
		l++;
		r--;
	}
	return 1;
}

int main() {
	string s;
	cin >> s;
	printf("%d\n", palin(s));

	return 0;
}