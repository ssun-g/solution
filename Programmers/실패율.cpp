#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, double> a, pair<int, double> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> s;
	vector<double> v(N + 2, 0);
	vector<double> fail(N + 2, 0);
	for (int i = 0; i < stages.size(); i++) {
		for (int j = 1; j <= stages[i]; j++) {
			v[j]++;
			if (j == stages[i]) {
				fail[j]++;
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (v[i] == 0) s.push_back(pair<int, double>(i, 0));
		else s.push_back(pair<int, double>(i, fail[i] / v[i]));
	}
	sort(s.begin(), s.end(), comp);
	for (int i = 0; i < s.size(); i++) {
		answer.push_back(s[i].first);
	}

	return answer;
}