#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main() {
	int n, m;
	string s;
	map<string, int> name;
	vector<pair<string, int>> v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++) {
		cin >> s;
		if (name.empty()) name.insert(pair<string, int>(s, 1));
		else {
			auto it = name.find(s);
			if (it != name.end()) it->second++;
			else name.insert(pair<string, int>(s, 1));
		}
	}

	for (auto it = name.begin(); it != name.end(); it++) {
		if (2 == it->second) v.push_back(pair<string, int>(it->first, it->second));
	}

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << '\n';
	}

	return 0;
}