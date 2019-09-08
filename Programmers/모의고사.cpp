#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int su1[5] = { 1,2,3,4,5 };
int su2[8] = { 2,1,2,3,2,4,2,5 };
int su3[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt(3);
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == su1[i % 5]) cnt[0]++;
		if (answers[i] == su2[i % 8]) cnt[1]++;
		if (answers[i] == su3[i % 10]) cnt[2]++;
	}
	int MAX = -1;
	MAX = max(max(cnt[0], cnt[1]), cnt[2]);
	for (int i = 0; i < 3; i++) {
		if (MAX == cnt[i]) answer.push_back(i + 1);
	}
	return answer;
}