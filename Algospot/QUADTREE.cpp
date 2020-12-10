#include<bits/stdc++.h>
using namespace std;

string reverse_quad(string::iterator& it) {
	char head = *(it++);
	if (head == 'w' || head == 'b')
		return string(1, head);

	string ul = reverse_quad(it);
	string ur = reverse_quad(it);
	string ll = reverse_quad(it);
	string lr = reverse_quad(it);

	return "x" + ll + lr + ul + ur;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		string s;
		cin >> s;

		string::iterator it = s.begin();
		cout << reverse_quad(it) << '\n';
	}

	return 0;
}