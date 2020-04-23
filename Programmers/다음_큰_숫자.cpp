#include <string>
#include <vector>

using namespace std;

int Count(int n) {
	int cnt = 0;
	while (n) {
		if (n % 2) cnt++;
		n /= 2;
	}
	return cnt;
}

int solution(int n) {
	int answer = 0;
	int i = n + 1;
	while (true) {
		if (Count(n) == Count(i)) {
			answer = i;
			break;
		}
		i++;
	}

	return answer;
}