#include<bits/stdc++.h>
using namespace std;

vector<char> vc;
map<char, int> mp;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		auto it = mp.find(s[0]);
		if (it != mp.end()) it->second++;
		else mp.insert(make_pair(s[0], 1));
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second >= 5) vc.push_back(it->first);
	}

	if (vc.empty()) cout << "PREDAJA" << '\n';
	else {
		sort(vc.begin(), vc.end());
		for (int i = 0; i < vc.size(); i++) {
			cout << vc[i];
		}
		cout << '\n';
	}

	return 0;
}