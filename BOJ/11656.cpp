#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	string st[1000];
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		st[i] = s.substr(i);
	}
	
	sort(st, st + s.length());

	for (int i = 0; i < s.length(); i++) {
		cout << st[i] << '\n';
	}

	return 0;
}