#include<iostream>
#include<string>
using namespace std;

int main() {
	int tc;
	string bfree;
	cin >> tc;
	getline(cin, bfree);
	while (tc--) {
		string s;
		string ans = "";
		getline(cin, s);
		int idx = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				for (int j = i - 1; j >= idx; j--) {
					ans += s[j];
				}
				ans += s[i];
				idx = i + 1;
			}
		}
		for (int i = s.length() - 1; i >= idx; i--) {
			ans += s[i];
		}
		cout << ans << '\n';
	}
	return 0;
}