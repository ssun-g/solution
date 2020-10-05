#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	list<char> ls;
	int M;
	string s;
	cin >> s;
	cin >> M;
	for (int i = 0; i < s.length(); i++) {
		ls.push_back(s[i]);
	}

	auto pos = ls.end();
	for (int i = 0; i < M; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == 'P') {
			char ch;
			cin >> ch;
			ls.insert(pos, ch);
		}
		else if (cmd == 'L') {
			if (pos == ls.begin()) continue;
			pos--;
		}
		else if (cmd == 'D') {
			if (pos == ls.end()) continue;
			pos++;
		}
		else if (cmd == 'B') {
			if (pos == ls.begin()) continue;
			pos--;
			pos = ls.erase(pos);
		}
	}

	for (auto it = ls.begin(); it != ls.end(); it++) {
		cout << *it;
	}

	return 0;
}