#include<iostream>>
#include<string>
using namespace std;

int main() {
	string s;
	int B;
	int answer = 0;
	cin >> s >> B;

	int digit = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		if ('0' <= s[i] && s[i] <= '9') answer += digit *(s[i] - '0');
		else answer += digit*(s[i] - 'A' + 10);
		digit *= B;
	}
	cout << answer << '\n';

	return 0;
}