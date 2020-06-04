#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int MAX = -1;
	for (int i = 0; i < budgets.size(); i++) {
		MAX = (MAX < budgets[i]) ? budgets[i] : MAX;
	}

	long long left = 1;
	long long right = MAX;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < budgets.size(); i++) {
			if (mid < budgets[i]) sum += mid;
			else sum += budgets[i];
		}
		if (sum < M) left = mid + 1;
		else right = mid - 1;
	}
	answer = right;
	return answer;
}