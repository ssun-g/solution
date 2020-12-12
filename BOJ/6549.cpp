#include<bits/stdc++.h>
using namespace std;

int height[100000];

long long solve(int left, int right) {
	if (left == right) return height[left];

	int mid = (left + right) / 2;
	long long maxHeight = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	long long h = min(height[lo], height[hi]);
	maxHeight = max(maxHeight, h * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || height[lo - 1] < height[hi + 1]))
			h = min(h, (long long)height[++hi]);
		else
			h = min(h, (long long)height[--lo]);

		maxHeight = max(maxHeight, h*(hi - lo + 1));
	}

	return maxHeight;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		memset(height, 0, sizeof(height));
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}
		cout << solve(0, n - 1) << '\n';
	}

	return 0;
}