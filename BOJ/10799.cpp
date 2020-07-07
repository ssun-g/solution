#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string s;
	stack<char> st;
	int result = 0;
	bool flag = false;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			flag = false;
		}
		else {
			st.pop();
			if (flag) result += 1;
			else result += st.size();
			flag = true;
		}
	}
	cout << result << '\n';

	return 0;
}