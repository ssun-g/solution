#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

map<string, string> mp;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		string phoneNum;
		cin >> s >> phoneNum;
		mp.insert(make_pair(s, phoneNum));
	}

	string name;
	while (cin >> name) {
		auto it = mp.find(name);
		if (it != mp.end()) cout << name << "=" << it->second << '\n';
		else cout << "Not found" << '\n';
	}

	return 0;
}