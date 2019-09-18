#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int sum = 0;
	bool answer = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P' || s[i] == 'p') sum++;
		else if (s[i] == 'Y' || s[i] == 'y') sum--;
	}
	if (sum) answer = false;
	return answer;
}