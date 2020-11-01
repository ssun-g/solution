#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(char a, char b) {
	return a > b;
}

int main() {
	vector<char> v;
	long long sum = 0;
	long long cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - '0' == 0) cnt++;
		sum += s[i] - '0';
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end(), comp);


	if (sum % 3 == 0 && cnt != 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else cout << "-1";

	return 0;
}