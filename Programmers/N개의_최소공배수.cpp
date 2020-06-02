#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
	int answer = 0;
	while (true) {
		int cnt = 0;
		answer++;
		for (int i = 0; i < arr.size(); i++) {
			if (answer % arr[i] == 0) cnt++;
		}
		if (cnt == arr.size()) break;
	}
	return answer;
}