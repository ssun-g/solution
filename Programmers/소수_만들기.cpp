#include <vector>
#include <iostream>
using namespace std;

int cnt;
int check[51];
int Prime[3001];

void Eras() {
	for (int i = 2; i*i <= 3000; i++) {
		if (!Prime[i]) {
			for (int j = i*i; j <= 3000; j += i) {
				Prime[j] = 1;
			}
		}
	}
}

void go(vector<int> nums, int idx, int sum, int count) {
	if (count == 3) {
		if (Prime[sum] == 0) cnt++;
		return;
	}
	for (int i = idx; i < nums.size(); i++) {
		if (!check[i]) {
			check[i] = 1;
			go(nums, i + 1, sum + nums[i], count + 1);
			check[i] = 0;
		}
	}
	return;
}

int solution(vector<int> nums) {
	int answer = -1;
	Eras();
	go(nums, 0, 0, 0);
	answer = cnt;

	return answer;
}