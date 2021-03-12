#include<bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	while (q--) {
		int query;
		cin >> query;
		if (query == 1) {
			int a, b;
			cin >> a >> b;

			// 구간 합
			long long sum = 0;
			for (int i = a; i <= b; i++) {
				sum += arr[i];
			}
			cout << sum << '\n';

			// swap
			swap(arr[a], arr[b]);
		}
		else if (query == 2) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;

			// 구간 합
			long long sumab = 0;
			long long sumcd = 0;
			for (int i = a; i <= b; i++) sumab += arr[i];
			for (int i = c; i <= d; i++) sumcd += arr[i];
			cout << sumab - sumcd << '\n';
		}
	}

	return 0;
}
