#include<iostream>>
#include<string>
using namespace std;

int main() {
	string s;
	string answer = "";
	cin >> s;

	for (int i = s.length() - 1; i >= 0; i--) {
		int bin = s[i] - '0';
		int cnt = 0;
		while (cnt < 3) {
			answer += to_string(bin % 2);
			bin /= 2;
			cnt++;
		}
	}

	bool fzero = false;
	for (int i = answer.length() - 1; i >= 0; i--) {
		if (answer[i] == '1') fzero = true;
		if (fzero) cout << answer[i];
	}
	if (!fzero && answer[0] == '0') cout << "0";

	return 0;
}