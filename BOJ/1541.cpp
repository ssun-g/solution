#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int ret = 0;
	int minus = 0;
	bool mflag = false;
	bool firstOper = true;
	string num = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (firstOper) {
				ret = stoi(num);
				firstOper = false;
			}

			else if (mflag) minus += stoi(num);
			else ret += stoi(num);

			num = "";
			if (s[i] == '-') mflag = true;
			continue;
		}
		num += s[i];
	}
	if (mflag) minus += stoi(num);
	else ret += stoi(num);

	return ret - minus;
}

int main() {
	string s;
	cin >> s;
	cout << solve(s) << '\n';

	return 0;
}