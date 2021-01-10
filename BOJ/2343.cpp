#include<bits/stdc++.h>
using namespace std;

int lesson[100000];

int main() {
	int answer = 1000000001;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> lesson[i];
	}

	int left = 0, right = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		int cnt = 1;
		bool flag = false; // lesson의 길이가 mid(블루레이 길이)보다 클 경우 판별
		for (int i = 0; i < N; i++) {
			if (mid < lesson[i]) {
				flag = true;
				break;
			}

			sum += lesson[i];
			if (sum > mid) {
				sum = lesson[i];
				cnt++;
			}
		}
		if (!flag && cnt <= M) {
			right = mid - 1;
			answer = min(answer, mid);
		}
		else left = mid + 1;
	}
	cout << answer << '\n';

	return 0;
}