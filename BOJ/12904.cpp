#include<bits/stdc++.h>
using namespace std;

vector<char> t;

int main() {
	string S, T;
	cin >> S >> T;

	for (int i = 0; i < T.length(); i++) t.push_back(T[i]);

	// S�� T�� ��ȯ�ϴ°� �ƴ� �ϼ��� ���ڿ� T�� S�� ��ȯ�غ���.
	while (S.length() != t.size()) {
		int last_char = t[t.size() - 1];
		t.pop_back();

		if (last_char == 'B') reverse(t.begin(), t.end());
	}

	// �ٸ� ���ڰ� ������ S�� T�� ���� �� ����.
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != t[i]) {
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;
}