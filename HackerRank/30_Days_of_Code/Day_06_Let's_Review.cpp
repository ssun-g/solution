#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		string odd = "";
		string even = "";
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (i % 2 == 0) even += s[i];
			else odd += s[i];
		}
		cout << even << ' ' << odd << '\n';
	}
	return 0;
}
