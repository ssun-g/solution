#include <string>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> game(int num, int cmp) {
	pair<int, int> p;
	int arr[3];
	int arr2[3];
	int idx = 2;
	int strike = 0;
	int ball = 0;
	while (num) {
		arr[idx] = num % 10;
		arr2[idx] = cmp % 10;
		num /= 10;
		cmp /= 10;
		idx--;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i] == arr2[j]) {
				if (i == j) strike++;
				else ball++;
			}
		}
	}
	p.first = strike;
	p.second = ball;

	return p;
}

int pass(int num) {
	int arr[3];
	int check[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int idx = 2;
	while (num) {
		arr[idx--] = num % 10;
		num /= 10;
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i] == 0) return 1;
		if (check[arr[i]]) return 1;
		check[arr[i]] = 1;
	}

	return 0;
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	pair<int, int> pa;
	for (int i = 123; i <= 987; i++) {
		if (pass(i)) continue;
		bool flag = false;
		for (int j = 0; j < baseball.size(); j++) {
			pa = game(baseball[j][0], i);
			if (pa.first != baseball[j][1] || pa.second != baseball[j][2]) {
				flag = true;
				break;
			}
		}
		if (!flag) answer++;
	}
	return answer;
}