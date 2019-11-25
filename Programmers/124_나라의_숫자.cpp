#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	string temp = "";
	while (n > 0) {
		if (n % 3 == 0) {
			temp += "4";
			n = n / 3 - 1;
			continue;
		}
		else if (n % 3 == 1) temp += "1";
		else temp += "2";

		n = n / 3;
	}
	for (int i = temp.length() - 1; i >= 0; i--) {
		answer += temp[i];
	}

	return answer;
}