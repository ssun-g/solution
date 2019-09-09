#include<cstdio>
#include<algorithm>
#define MAX 1000000
using namespace std;

long long tree[MAX];
long long Max, sum;

int main() {
	long long n, m;
	long long left, right, mid;
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
		if (tree[i] > Max)
			Max = tree[i];
	}

	left = 0;
	right = Max;

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		if (sum < m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%lld", right);

	return 0;
}