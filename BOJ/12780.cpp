#include<iostream>
#include<string>
using namespace std;

int main() {
	int cnt = 0;
	string s;
	string st;
	cin >> s >> st;
	while (true) {
		auto p = s.find(st);
		if (p == string::npos) break;
		s.erase(0, p + st.length());
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}