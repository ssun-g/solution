#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool comp2(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair<int, int> > vp;
	vector<pair<string, int> > tmp;
	unordered_map<string, int> ump;

	for (int i = 0; i < genres.size(); i++) {
		ump[genres[i]] += plays[i];
	}

	for (auto it = ump.begin(); it != ump.end(); it++) {
		tmp.push_back(make_pair(it->first, it->second));
	}
	sort(tmp.begin(), tmp.end(), comp);

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < genres.size(); j++) {
			if (tmp[i].first == genres[j]) {
				vp.push_back(make_pair(plays[j], j));
			}
		}
		sort(vp.begin(), vp.end(), comp2);

		int cnt = 0;
		for (int i = 0; i < vp.size(); i++) {
			if (cnt == 2) break;
			answer.push_back(vp[i].second);
			cnt++;
		}
		vp.clear();
	}

	return answer;
}