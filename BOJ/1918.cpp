#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	stack<char> op;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			cout << s[i];
			continue;
		}

		if (s[i] == '(') op.push('(');
		else if (s[i] == ')') {
			while (op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
		else if (s[i] == '*' || s[i] == '/') {
			if (op.empty() || op.top() == '(' || op.top() == '+' || op.top() == '-') op.push(s[i]);
			else {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (op.empty() || op.top() == '(') op.push(s[i]);
			else {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
		}
	}

	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}

	return 0;
}