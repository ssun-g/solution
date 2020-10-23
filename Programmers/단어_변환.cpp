#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int MIN = 987654321;
unordered_map<string, int> ump;

void dfs(string cur, string target, vector<string> words, int depth) {
	if (cur == target) {
		MIN = min(MIN, depth);
		return;
	}

	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < words[i].size(); j++) {
			if (ump[words[i]] == 0 && cur[j] != words[i][j]) cnt++;
		}
		if (cnt == 1) {
			ump[words[i]] = 1;
			dfs(words[i], target, words, depth + 1);
			ump[words[i]] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	dfs(begin, target, words, 0);
	if (MIN == 987654321) answer = 0;
	else answer = MIN;

	return answer;
}