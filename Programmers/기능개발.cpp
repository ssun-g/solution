#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> days;
	int cnt = 0;
	int i = 0;

	while (i < progresses.size()) {
		progresses[i] += speeds[i];
		cnt++;
		if (progresses[i] >= 100) {
			days.push(cnt);
			i++;
			cnt = 0;
		}
	}

	cnt = 1;
	int d = days.front();
	days.pop();
	while (!days.empty()) {
		if (days.front() <= d) {
			cnt++;
			days.pop();
		}
		else {
			answer.push_back(cnt);
			cnt = 0;
			d = days.front();
		}
		i++;
	}
	answer.push_back(cnt);

	return answer;
}