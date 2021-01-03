#include<bits/stdc++.h>
using namespace std;

// a의 길이가 길거나 같도록 제한을 둔다.
string solve(string a, string b) {
	string ret = "";
	int llen = a.length(), slen = b.length();

	int up = 0;
	for (int i = slen - 1; i >= 0; i--) {
		int n = a[i + (llen - slen)] - '0';
		int m = b[i] - '0';
		int sum = n + m + up;
		if (sum >= 10) up = sum / 10;
		else up = 0;
		ret += (sum % 10) + '0';
	}

	for (int i = llen - slen - 1; i >= 0; i--) {
		int n = a[i] - '0';
		n += up;
		if (n >= 10) up = n / 10;
		else up = 0;
		ret += (n % 10) + '0';
	}
	if (up != 0) ret += up + '0';

	reverse(ret.begin(), ret.end());

	return ret;
}

int main() {
	string a, b;
	cin >> a >> b;
	if (a.length() >= b.length()) cout << solve(a, b) << '\n';
	else cout << solve(b, a) << '\n';

	return 0;
}