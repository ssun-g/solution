#include <string>
#include <math.h>

using namespace std;

int arr[3];

int solution(string dartResult) {
	string s = "";
	int answer = 0;
	int idx = 0;
	for (int i = 0; i < dartResult.length(); i++) {
		if (dartResult[i] == 'S') {
			arr[idx++] = stoi(s);
			s = "";
		}
		else if (dartResult[i] == 'D') {
			arr[idx++] = pow(stoi(s), 2);
			s = "";
		}
		else if (dartResult[i] == 'T') {
			arr[idx++] = pow(stoi(s), 3);
			s = "";
		}
		else if (dartResult[i] == '#') {
			arr[idx - 1] *= -1;
			s = "";
		}
		else if (dartResult[i] == '*') {
			if (idx > 1) arr[idx - 2] *= 2;
			arr[idx - 1] *= 2;
			s = "";
		}
		else s += dartResult[i];
	}
	for (int i = 0; i < 3; i++) answer += arr[i];

	return answer;
}