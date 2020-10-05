#include<iostream>
#include<string>
using namespace std;

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	string f = a + b;
	string s = c + d;

	cout << stoll(f) + stoll(s) << '\n';

	return 0;
}