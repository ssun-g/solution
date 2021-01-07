#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int sum = 0, cnt = 0, plus = 1;
	while (sum < N) {
		if (sum + plus > N) {
			plus = 1;
			continue;
		}
		sum += plus;
		plus++;
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}