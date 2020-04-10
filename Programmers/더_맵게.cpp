#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);
	while (pq.top() < K) {
		if (pq.size() < 2) {
			answer = -1;
			break;
		}
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(a + b * 2);
		answer++;
	}

	return answer;
}