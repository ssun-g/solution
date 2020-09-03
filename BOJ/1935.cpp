#include<iostream>
#include<string>
#include<stack>
using namespace std;

double alpha[26];

int main() {
	stack<double> post_order;
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> alpha[i];
	}

	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') post_order.push((int)alpha[s[i] - 'A']);
		else {
			double second = post_order.top();
			post_order.pop();
			double first = post_order.top();
			post_order.pop();
			if (s[i] == '*') post_order.push(first*second);
			else if (s[i] == '/') post_order.push(first / second);
			else if (s[i] == '+') post_order.push(first + second);
			else if (s[i] == '-') post_order.push(first - second);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << post_order.top() << '\n';

	return 0;
}