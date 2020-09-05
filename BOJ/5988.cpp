#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[s.length() - 1] == '0' || s[s.length() - 1] == '2'
			|| s[s.length() - 1] == '4' || s[s.length() - 1] == '6'
			|| s[s.length() - 1] == '8') cout << "even" << '\n';
		else cout << "odd" << '\n';
	}

	return 0;
}