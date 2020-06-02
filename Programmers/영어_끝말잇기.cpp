#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

bool mCmp(string word) {
	for (auto it = m.begin(); it != m.end(); it++) {
		if (word == it->first) return false;
	}
	return true;
}

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	int people = 1;
	int turn = 1;
	for (int i = 0; i < words.size(); i++) {
		if (n < people) {
			people = 1;
			turn++;
		}

		if (!mCmp(words[i]) || (i != 0 && (words[i - 1][words[i - 1].size() - 1] != words[i][0]))) {
			answer.push_back(people);
			answer.push_back(turn);
			break;
		}
		else if (m.empty() || mCmp(words[i])) m.insert(pair<string, int>(words[i], 0));
		people++;
	}
	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}