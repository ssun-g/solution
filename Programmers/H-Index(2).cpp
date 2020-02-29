#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int solution(vector<int> citations) {
	int answer = 0;
	int i;
	sort(citations.begin(), citations.end(), comp);
	for (i = 0; i < citations.size(); i++) {
		if (citations[i] <= i) break;
	}
	return answer;
}