#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int sum = 0;
	int xtmp = x;
	while (xtmp > 0) {
		sum += xtmp % 10;
		xtmp /= 10;
	}
	if (x%sum) answer = false;
	return answer;
}