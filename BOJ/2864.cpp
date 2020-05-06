#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int mini(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6') s[i] = '5';
	}

	return stoi(s);
}

int maxi(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '5') s[i] = '6';
	}

	return stoi(s);
}

int main() {
	int MIN, MAX;
	string a, b;
	cin >> a >> b;
	MIN = mini(a) + mini(b);
	MAX = maxi(a) + maxi(b);
	printf("%d %d\n", MIN, MAX);

	return 0;
}