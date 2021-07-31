#include<bits/stdc++.h>
using namespace std;

vector<char> t;

int main() {
	string S, T;
	cin >> S >> T;

	for (int i = 0; i < T.length(); i++) t.push_back(T[i]);

	// S를 T로 변환하는게 아닌 완성된 문자열 T를 S로 변환해본다.
	while (S.length() != t.size()) {
		int last_char = t[t.size() - 1];
		t.pop_back();

		if (last_char == 'B') reverse(t.begin(), t.end());
	}

	// 다른 문자가 있으면 S를 T로 만들 수 없다.
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != t[i]) {
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;
}