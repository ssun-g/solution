#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long MAX = -1;
	for (int i = 0; i < times.size(); i++) {
		if (MAX < times[i]) MAX = times[i];
	}

	long long left = 1;
	long long right = MAX*n;
	long long mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		long long total = 0;
		for (int i = 0; i < times.size(); i++) {
			total += mid / times[i];
		}
		if (total < n) left = mid + 1;
		else right = mid - 1;
	}
	answer = left;
	return answer;
}