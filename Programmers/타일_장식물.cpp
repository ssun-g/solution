#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	vector<long long> dp;
	dp.push_back(1);
	dp.push_back(6);
	dp.push_back(10);
	for (int i = 3; i < N; i++) {
		dp.push_back(dp[i - 1] + dp[i - 2]);
	}
	answer = dp[N - 1];
	return answer;
}