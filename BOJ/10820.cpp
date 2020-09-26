#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int low = 0;
		int upp = 0;
		int num = 0;
		int blk = 0;
		for (int i = 0; i < s.length(); i++) {
			if ('a' <= s[i] && s[i] <= 'z')  low++;
			else if ('A' <= s[i] && s[i] <= 'Z') upp++;
			else if ('0' <= s[i] && s[i] <= '9') num++;
			else if (s[i] == ' ') blk++;
		}
		cout << low << ' ';
		cout << upp << ' ';
		cout << num << ' ';
		cout << blk << '\n';
	}

	return 0;
}