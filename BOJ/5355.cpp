#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		double num;
		cin >> num;

		string s;
		getline(cin, s);

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '@') num *= 3;
			else if (s[i] == '%') num += 5;
			else if (s[i] == '#') num -= 7;
		}

		cout << fixed;
		cout.precision(2);
		cout << num << '\n';
	}

	return 0;
}