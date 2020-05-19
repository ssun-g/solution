#include <string>
#include <vector>
#include <queue>

using namespace std;

int check[20000];
priority_queue<int, vector<int>, less<int>> pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int sum = stock;
	while (stock < k) {
		for (int i = 0; i < dates.size(); i++) {
			if (!check[i] && dates[i] <= stock) {
				pq.push(supplies[i]);
				check[i] = 1;
			}
		}
		stock += pq.top();
		pq.pop();
		answer++;
	}

	return answer;
}