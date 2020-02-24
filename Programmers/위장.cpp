#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check[30];
int item[30];

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	int idx = 1;
	int result = 1;
	string cur;

	for (int i = 0; i < clothes.size(); i++) {
		cur = clothes[i][1];
		if (!check[i]) {
			check[i] = 1;
			item[i] = idx;
			for (int j = 0; j < clothes.size(); j++) {
				if (!check[j] && (cur == clothes[j][1])) {
					check[j] = 1;
					item[j] = idx;
				}
			}
			idx++;
		}
	}

	for (int i = 1; i < idx; i++) {
		int cnt = 0;
		for (int j = 0; j < clothes.size(); j++) {
			if (i == item[j]) cnt++;
		}
		result *= cnt + 1;
	}

	answer = result - 1;
	return answer;
}