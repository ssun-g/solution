#include<iostream>
#include<string>
using namespace std;

int main() {
	int tc;
	string s;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		string a, b;
		cin >> s;
		a = s[0];
		b = s[2];
		printf("%d\n", stoi(a) + stoi(b));
	}

	return 0;
}