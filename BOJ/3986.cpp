#include<iostream>
#include<string>
#include<stack>
using namespace std;

double alpha[26];

int main() {
	int n;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> st;
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (st.empty() || st.top() != s[j]) st.push(s[j]);
			else if (st.top() == s[j]) st.pop();
		}
		if (st.empty()) answer++;
	}
	cout << answer << '\n';

	return 0;
}