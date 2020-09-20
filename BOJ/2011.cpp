#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[5001];

int main() {
	string s;
	string tmp = "";
	cin >> s;
	if (s[0] == '0') {
		cout << "0";
		return 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	tmp += s[0];
	for (int i = 2; i <= s.length(); i++) {
		tmp += s[i - 1];
		if (s[i - 1] > '0')
			dp[i] = dp[i - 1];

		if (10 <= stoi(tmp) && stoi(tmp) <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		tmp = "";
		tmp += s[i - 1];
	}
	cout << dp[s.length()];

	return 0;
}