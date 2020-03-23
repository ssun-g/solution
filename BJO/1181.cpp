#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;

bool comp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {
	int tc;
	string s;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		cin >> s;
		if (find(v.begin(), v.end(), s) == v.end()) v.push_back(s);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}