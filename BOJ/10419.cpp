#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int d;
		cin >> d;
		for (int i = 1; i <= d; i++) {
			// 지각 시간이 i일 때, i + (i*i)가 수업 시간보다 크다면 교수님이 최대로 지각할 수 있는 시간은 i-1
			if (i + (i*i) > d) {
				cout << i - 1 << '\n';
				break;
			}
		}
	}

	return 0;
}