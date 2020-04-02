#include <string>
#include <vector>

using namespace std;

int check[26];

void Reset() {
	for (int i = 0; i < 26; i++) {
		check[i] = -1;
	}
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		Reset();
		for (int j = 0; j < skill.length(); j++) {
			for (int k = 0; k < skill_trees[i].size(); k++) {
				if (skill[j] == skill_trees[i][k]) {
					check[j] = k;
					break;
				}
			}
		}

		// possible check
		bool flag = false;
		bool result = true;
		if (check[0] == -1) flag = true;
		for (int j = 1; j < skill.length(); j++) {
			if (check[j] == -1) flag = true;
			if (flag && check[j] != -1) {
				result = false;
				break;
			}
			if (!flag && check[j - 1] - check[j] > 0) {
				result = false;
				break;
			}
		}
		if (result) answer++;
	}
	return answer;
}