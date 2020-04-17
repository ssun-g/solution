#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	string st = "";
	vector<int> v;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			v.push_back(stoi(st));
			st = "";
			continue;
		}
		st += s[i];
	}
	v.push_back(stoi(st));

	sort(v.begin(), v.end());
	answer += to_string(v[0]);
	answer += " ";
	answer += to_string(v[v.size() - 1]);

	return answer;
}