#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		char tmp = s[i];
		for (int j = i + 1; j <= s.length() - 1; j++) {
			if (s[i] < s[j]) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
		answer = s;
	}
	return answer;
}