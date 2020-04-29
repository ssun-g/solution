#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

bool comp2(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair<int, int>> v;
	vector<pair<string, int>> vec;
	map<string, int> m;
	map<string, int> ::iterator it;
	m.insert(pair<string, int>(genres[0], plays[0]));
	for (int i = 1; i < genres.size(); i++) {
		it = m.find(genres[i]);
		if (it != m.end()) it->second += plays[i];
		else m.insert(pair<string, int>(genres[i], plays[i]));
	}

	for (it = m.begin(); it != m.end(); it++) {
		vec.push_back(pair<string, int>(it->first, it->second));
	}
	sort(vec.begin(), vec.end(), comp2);

	for (int j = 0; j < vec.size(); j++) {
		int MAX = -1;
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < genres.size(); i++) {
			if (vec[j].first == genres[i]) {
				v.push_back(pair<int, int>(plays[i], i));
			}
		}

		sort(v.begin(), v.end(), comp);
		for (int i = 0; i < v.size(); i++) {
			if (flag) cnt = -1;
			if (v.size() < 2) flag = true;
			if (cnt == 2) break;
			answer.push_back(v[i].second);
			cnt++;
		}
		v.clear();
	}

	return answer;
}