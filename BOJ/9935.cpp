#include<iostream>
#include<string>
using namespace std;

char answer[1000001];

int main() {
	string s;
	string b;
	int idx = 0;
	cin >> s >> b;

	int len = b.length();
	for (int i = 0; i < s.length(); i++) {
		answer[idx++] = s[i];
		if (answer[idx - 1] == b[len - 1]) {
			if (idx < len) continue;
			bool bomb = true;
			for (int j = 0; j < len; j++) {
				if (answer[idx - 1 - j] != b[len - 1 - j]) {
					bomb = false;
					break;
				}
			}
			if (bomb) idx = idx - len;
		}
	}

	if (idx <= 0) cout << "FRULA" << '\n';
	else {
		for (int i = 0; i < idx; i++) {
			cout << answer[i];
		}
		cout << '\n';
	}

	return 0;
}