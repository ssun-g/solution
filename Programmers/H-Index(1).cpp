#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	for (int i = 10000; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) cnt++;
		}
		if (cnt == i) answer = cnt;
	}
	return answer;
}