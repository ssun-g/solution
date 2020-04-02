#include <string>
#include <vector>

using namespace std;

vector<char> bar;

int solution(string arrangement) {
	int answer = 0;
	bool flag = false;
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') {
			bar.push_back(arrangement[i]);
			flag = true;
		}
		else {
			bar.pop_back();
			if (flag) answer += bar.size();
			else answer++;
			flag = false;
		}
	}

	return answer;
}