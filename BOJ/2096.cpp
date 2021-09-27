/*

배열을 선언해서 dp를 구현하면 메모리 초과 발생.
1149번 문제와 비슷하게 배열을 선언하지 않고 dp를 구현하면 된다.

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int max_prev_a, max_prev_b, max_prev_c, min_prev_a, min_prev_b, min_prev_c;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int min_a = a;
		int min_b = b;
		int min_c = c;

		if (i == 0) {
			max_prev_a = a;
			max_prev_b = b;
			max_prev_c = c;

			min_prev_a = a;
			min_prev_b = b;
			min_prev_c = c;

			continue;
		}

		a += max(max_prev_a, max_prev_b);
		b += max(max_prev_a, max(max_prev_b, max_prev_c));
		c += max(max_prev_b, max_prev_c);

		min_a += min(min_prev_a, min_prev_b);
		min_b += min(min_prev_a, min(min_prev_b, min_prev_c));
		min_c += min(min_prev_b, min_prev_c);

		max_prev_a = a;
		max_prev_b = b;
		max_prev_c = c;

		min_prev_a = min_a;
		min_prev_b = min_b;
		min_prev_c = min_c;
	}

	cout << max(max_prev_a, max(max_prev_b, max_prev_c)) << ' ';
	cout << min(min_prev_a, min(min_prev_b, min_prev_c)) << '\n';

	return 0;
}