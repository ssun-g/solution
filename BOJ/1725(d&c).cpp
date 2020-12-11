#include<bits/stdc++.h>
using namespace std;

int height[100000];

int solve(int left, int right) {
	if (left == right) return height[left];

	int mid = (left + right) / 2;
	int maxHeight = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int h = min(height[lo], height[hi]);
	maxHeight = max(maxHeight, h * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || height[lo - 1] < height[hi + 1]))
			h = min(h, height[++hi]);
		else
			h = min(h, height[--lo]);

		maxHeight = max(maxHeight, h*(hi - lo + 1));
	}

	return maxHeight;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}
	cout << solve(0, N - 1) << '\n';

	return 0;
}