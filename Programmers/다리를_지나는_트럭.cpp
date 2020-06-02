#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> qDone;
queue<int> qCross;
queue<int> t;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int total = 0;
	int idx = 0;
	while (qDone.size() != truck_weights.size()) {
		int tt = t.front();
		if (answer - tt == bridge_length) {
			int tmp = qCross.front();
			qDone.push(tmp);
			total -= tmp;
			qCross.pop();
			t.pop();
		}
		if (total + truck_weights[idx] <= weight) {
			total += truck_weights[idx];
			qCross.push(truck_weights[idx]);
			t.push(answer);
			idx++;
		}
		answer++;
	}

	return answer;
}