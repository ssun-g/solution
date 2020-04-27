#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string s;
	string result;
	scanf("%d", &n);
	cin >> s;
	result = s;
	for (int i = 1; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] != tmp[j]) result[j] = '?';
		}
	}
	cout << result << '\n';

	return 0;
}