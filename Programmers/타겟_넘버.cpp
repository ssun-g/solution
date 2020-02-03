#include <string>
#include <vector>

using namespace std;

int result = 0;

void dfs(vector<int> numbers, int target, int sum, int cnt) {
	if (cnt == numbers.size()) {
		if (sum == target) result++;
		return;
	}
	dfs(numbers, target, sum + numbers[cnt], cnt + 1);
	dfs(numbers, target, sum - numbers[cnt], cnt + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, target, 0, 0);
	answer = result;
	return answer;
}