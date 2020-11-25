#include<iostream>
using namespace std;

int main() {
	int n;
	int answer;
	cin >> n;
	if (n % 2 == 0) { // 검지 or 약지
		if ((n / 4) % 2 == 0) answer = 2; // 검지
		else answer = 4; // 약지
	}

	else { // 엄지 or 중지 or 새끼
		if ((n / 2) % 2 == 1) answer = 3; // 중지
		else { // 엄지 or 새끼
			if (((n / 2) / 2) % 2 == 0) answer = 1; // 엄지
			else answer = 5; // 새끼
		}
	}
	cout << answer;

	return 0;
}