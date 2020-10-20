#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int, int>> srt;
	map<int, int> mp;
	string tmp = "";

	// input map container
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			if (mp.empty() || mp.find(stoi(tmp)) == mp.end()) mp.insert(make_pair(stoi(tmp), 1));
			else mp.find(stoi(tmp))->second++;
			tmp = "";
		}
		if ('0' <= s[i] && s[i] <= '9') tmp += s[i];
	}
	if (mp.empty() || mp.find(stoi(tmp)) == mp.end()) mp.insert(make_pair(stoi(tmp), 1));
	else mp.find(stoi(tmp))->second++;

	// copy to vector
	for (auto it = mp.begin(); it != mp.end(); it++) {
		srt.push_back(make_pair(it->first, it->second));
	}
	sort(srt.begin(), srt.end(), comp);

	for (int i = 0; i < srt.size(); i++) {
		answer.push_back(srt[i].first);
	}

	return answer;
}