#include <bits/stdc++.h>
using namespace std;

int main() {
	string song[15] = { "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu",
		"in", "bed", "tururu", "turu", "baby", "sukhwan" };
	int n;
	cin >> n;
	n--;

	int checkTuru = n % 14; // tururu, turu check
	int verse = n / 14; // verse check

	if (song[checkTuru] == "tururu") { // 1절을 기준으로 tururu 위치일 경우
		if (verse >= 3) cout << "tu+ru*" << verse + 2; // 3절 이상일 경우 ru의 등장 횟수가 5이상이다.
		else {
			cout << "tururu";
			for (int i = 1; i <= verse; i++) cout << "ru";
		}
	}
	else if (song[checkTuru] == "turu") { // 1절을 기준으로 turu 위치일 경우
		if (verse >= 4) { // 4절 이상일 경우 ru의 등장 횟수가 5 이상이다.
			cout << "tu+ru*" << verse + 1;
		}
		else {
			cout << "turu";
			for (int i = 1; i <= verse; i++) cout << "ru";
		}
	}
	else cout << song[checkTuru]; // tururu, turu가 아닐 경우 해당 word를 출력

	return 0;
}