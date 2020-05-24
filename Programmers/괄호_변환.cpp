#include <string>
#include <vector>
#include <stack>

using namespace std;

bool cmpc(string p) {
	stack<char> st;
	if (p[0] == ')') return false;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == ')') {
			if (st.empty()) return false;
			st.pop();
		}
		else st.push(p[i]);
	}
	return true;
}

bool cmpb(string p) {
	int o = 0;
	int c = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') o++;
		else c++;
	}
	if (o == c) return true;
	else return false;
}

string go(string p) {
	if (p == "") return "";
	for (int i = 1; i < p.length(); i += 2) {
		string u = "";
		string v = "";
		for (int j = 0; j <= i; j++) u += p[j];
		for (int j = i + 1; j < p.length(); j++) v += p[j];
		if (!cmpb(u)) continue;
		if (cmpc(u)) return u += go(v);
		else {
			string s = "";
			string tmp = "";
			s += '(';
			s += go(v);
			s += ')';
			for (int i = 0; i < u.length(); i++) {
				if (i == 0 || i == u.length() - 1) continue;
				if (u[i] == '(') tmp += ')';
				else tmp += '(';
			}
			s += tmp;
			return s;
		}
	}
}

string solution(string p) {
	string answer = "";
	if (cmpc(p)) return p;
	answer = go(p);

	return answer;
}