#include<iostream>>
#include<string>
using namespace std;

int main() {
	string s;
	string answer = "";
	cin >> s;

	int cnt = 0;
	string tmp = "";
	int digit = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		int sum = 0;
		tmp += s[i];
		cnt++;
		if ((cnt != 0 && cnt % 3 == 0) || i == 0) {
			int bindg = 1;
			for (int i = 0; i < tmp.length(); i++) {
				sum += bindg*(tmp[i] - '0');
				bindg *= 2;
			}
			tmp = "";
			answer += to_string(sum);
		}
	}

	for (int i = answer.length() - 1; i >= 0; i--) {
		cout << answer[i];
	}

	return 0;
}