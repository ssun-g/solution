#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0 || flag) {
			answer += toupper(s[i]);
			flag = false;
		}
		else answer += tolower(s[i]);

		if (s[i] == ' ') flag = true;
		else flag = false;
	}
	return answer;
}