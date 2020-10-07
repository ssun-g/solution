#include<iostream>
#include<string>
using namespace std;

int main() {
	int num;
	string answer = "";
	cin >> num;
	while (num != 0) {
		if (num%-2 == 0) {
			answer += "0";
			num /= -2;
		}
		else {
			answer += "1";
			if (num < 0) num = num / -2 + 1;
			else num /= -2;
		}
	}

	if (answer == "") cout << "0";
	for (int i = answer.length() - 1; i >= 0; i--) {
		cout << answer[i];
	}

	return 0;
}