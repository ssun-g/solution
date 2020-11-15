#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

bool broken_num[10];

bool isBroken(int n) {
	if (n == 0) {
		if (broken_num[0]) return true;
		else return false;
	}

	while (n) {
		if (broken_num[n % 10]) return true;
		n /= 10;
	}

	return false;
}

int len(int n) {
	if (0 <= n && n <= 9) return 1;

	int cnt = 0;
	while (n) {
		n /= 10;
		cnt++;
	}

	return cnt;
}

int main() {
	int num;
	int size;
	cin >> num >> size;
	for (int i = 0; i < size; i++) {
		int bnum;
		cin >> bnum;
		broken_num[bnum] = true;
	}

	int MIN = abs(num - 100);
	for (int i = 0; i < 1000000; i++) {
		if (isBroken(i)) continue;

		int length = len(i);
		int tmp = abs(num - i);
		MIN = min(MIN, tmp + length);
	}
	cout << MIN << '\n';

	return 0;
}