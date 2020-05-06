#include<iostream>
#include<string>
using namespace std;

int main() {
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') cnt++;
	}
	cout << cnt << '\n';

	return 0;
}