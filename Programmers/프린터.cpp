#include <string>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	bool flag;

	pair<int, int> p;
	deque<pair<int, int> > dq;

	for (int i = 0; i < priorities.size(); i++) {
		p.first = i;
		p.second = priorities[i];
		dq.push_back(p);
	}

	while (!dq.empty()) {
		flag = false;
		for (int j = 1; j < dq.size(); j++) {
			if (dq[0].second < dq[j].second) {
				flag = true;
				dq.push_back(dq[0]);
				dq.pop_front();
				break;
			}
		}
		if (!flag) {
			answer++;
			if (dq.front().first == location) {
				dq.pop_front();
				break;
			}
			dq.pop_front();
		}
	}
	return answer;
}