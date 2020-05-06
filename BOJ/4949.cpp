#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;

stack<char> st;

void Reset() {
	while (!st.empty()) {
		st.pop();
	}
}

int main() {
	string s;
	while (true) {
		bool flag = false;
		Reset();
		getline(cin, s);
		if (s == ".") break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') st.push(s[i]);
			if (s[i] == ')') {
				if(!st.empty() && st.top() == '(') st.pop();
				else {
					flag = true;
					break;
				}
			}
			if (s[i] == ']') {
				if(!st.empty() && st.top() == '[') st.pop();
				else {
					flag = true;
					break;
				}
			}
		}
		if (!st.empty() || flag) printf("no\n");
		else printf("yes\n");
	}

	return 0;
}