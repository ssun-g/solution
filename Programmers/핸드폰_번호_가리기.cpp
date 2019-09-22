#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	int cnt = 0;
	for (int i = 0; i < phone_number.length(); i++) {
		if (phone_number.length() - cnt <= 4) answer += phone_number[i];
		else answer += "*";
		cnt++;
	}
	return answer;
}