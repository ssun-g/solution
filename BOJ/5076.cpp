#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main() {
	while (true) {
		stack<string> st;
		string s;
		string tag = "";
		bool flag = false;
		bool isClosed = false;
		bool bp = false;
		getline(cin, s);
		if (s == "#") break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ' && s[i + 1] != '/' && flag) {
				flag = false;
				tag += '>';
			}
			if (s[i] == '/' && flag) {
				isClosed = true;
				continue;
			}
			if (s[i] == '<') flag = true;
			if (flag) tag += s[i];
			if (s[i] == '>') {
				if (isClosed) {
					if (s[i - 1] == '/') {
						tag = "";
						flag = false;
						isClosed = false;
						continue;
					}
					if (!st.empty() && st.top() == tag) st.pop();
					else {
						bp = true;
						cout << "illegal" << '\n';
						break;
					}
				}
				else st.push(tag);

				tag = "";
				flag = false;
				isClosed = false;
			}
		}
		if (!st.empty() && !bp) cout << "illegal" << '\n';
		else if (st.empty() && !bp) cout << "legal" << '\n';
	}

	return 0;
}