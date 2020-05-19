#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int i, idx = 0;
	sort(people.begin(), people.end());
	for (i = people.size() - 1; i > idx; i--) {
		if (people[idx] + people[i] <= limit) idx++;
		answer++;
	}
	if (i == idx) answer++;
	return answer;
}