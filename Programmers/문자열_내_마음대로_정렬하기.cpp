#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	for (int i = 0; i < strings.size(); i++) {
		for (int j = i + 1; j <= strings.size() - 1; j++) {
			if (strings[i][n] > strings[j][n]) {
				answer.push_back(strings[i]);
				strings[i] = strings[j];
				strings[j] = answer.front();
				answer.pop_back();
			}
			else if (strings[i][n] == strings[j][n] && strings[i] > strings[j]) {
				answer.push_back(strings[i]);
				strings[i] = strings[j];
				strings[j] = answer.front();
				answer.pop_back();
			}
		}
	}
	answer = strings;
	return answer;
}