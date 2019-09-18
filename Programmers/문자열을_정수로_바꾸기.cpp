#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int digit = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '-' || s[i] == '+') break;
		answer += digit*(s[i] - '0');
		digit *= 10;
	}
	if (s[0] == '-') answer = answer*-1;
	return answer;
}