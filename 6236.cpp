#include<bits/stdc++.h>
using namespace std;

int money[100000];

int main() {
	int answer = 1000000001;
	int N, M;
	int left = 0, right = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		right += money[i];
	}

	while (left <= right) {
		int mid = (left + right) / 2; // 필요한 최소 금액
		int cnt = 1;
		int sum = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			// 하루에 써야하는 돈보다 인출 금액이 적다면 고려하지 않는다.
			if (mid < money[i]) {
				flag = true;
				break;
			}

			sum += money[i];
			if (sum > mid) {
				sum = money[i];
				cnt++;
			}
		}

		if (!flag && cnt <= M) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << answer << '\n';

	return 0;
}