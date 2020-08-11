#include <bits/stdc++.h>

using namespace std;

string toBinary(int n) {
	string bin = "";
	while (n) {
		bin += to_string(n % 2);
		n /= 2;
	}
	return bin;
}

int checkLength(string s) {
	int MAX = -1;
	int cnt = 0;
	for (int i = s.length() - 2; i >= 0; i--) {
		if (s[i + 1] == '1') cnt++;
		else {
			MAX = max(cnt, MAX);
			cnt = 0;
		}
	}
	if (s[0] == '1') {
		if (s[1] == '1') cnt++;
	}
	MAX = max(MAX, cnt);

	return MAX;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	printf("%d\n", checkLength(toBinary(n)));


	return 0;
}
