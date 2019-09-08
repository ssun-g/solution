#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int mid;
	bool odd;
	if (s.length() % 2) {
		odd = true;
		mid = s.length() / 2;
		answer = s[mid];
	}
	else {
		odd = false;
		mid = s.length() / 2 - 1;
		for (int i = 0; i < 2; i++) answer += s[mid++];
	}
	return answer;
}