#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;
		if (s[i] < 'a') s[i] = (s[i] + n - 'A') % 26 + 'A';
		if (s[i] >= 'a') s[i] = (s[i] + n - 'a') % 26 + 'a';
	}
	answer = s;
	return answer;
}