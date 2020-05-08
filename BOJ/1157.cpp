#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int alpha[26];

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') alpha[(int)(s[i] - 'a')]++;
		else alpha[(int)(s[i] - 'A')]++;
	}

	for (int i = 0; i < 26; i++) {
		v.push_back(pair<int, int>(alpha[i], i));
	}

	sort(v.begin(), v.end(), comp);

	if (v[0].first == v[1].first) cout << '?' << '\n';
	else cout << (char)(v[0].second + 'A') << '\n';

	return 0;
}