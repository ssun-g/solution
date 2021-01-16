#include<bits/stdc++.h>
using namespace std;

int arr[5000];

int solve(int size) {
	int ret = 1;
	int cnt = 1;
	int flag = -9; // 1: arr[i] < arr[i+1], 0: arr[i] == arr[i+1], -1: arr[i] > arr[i+1]
	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j < size - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				if (flag == 1 || flag == 0) cnt++;
				else cnt = 1;

				if (cnt == 2) {
					flag = -9;
					break;
				}
				flag = 1;
				ret = max(ret, ((j + 1) - i) + 1);
			}
			else if (arr[j] == arr[j + 1]) {
				if (flag != -9) cnt++;
				else cnt = 1;

				if (cnt == 2) {
					flag = -9;
					break;
				}
				flag = 0;
				ret = max(ret, ((j + 1) - i) + 1);
			}
			else {
				if (flag == -1 || flag == 0) cnt++;
				else cnt = 1;

				if (cnt == 2) {
					flag = -9;
					break;
				}
				flag = -1;
				ret = max(ret, ((j + 1) - i) + 1);
			}
		}
	}

	return ret;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << solve(N) << '\n';

	return 0;
}