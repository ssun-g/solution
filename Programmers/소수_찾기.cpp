#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> erato(n + 2);
	for (int i = 2; i*i <= n; i++) {
		if (!erato[i]) {
			for (int j = i*i; j <= n; j += i)
				erato[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!erato[i]) answer++;
	}
	return answer;
}