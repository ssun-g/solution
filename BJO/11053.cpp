#include <cstdio>
#include <algorithm>
using namespace std;

int length, n;
int arr[1001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int here;
		scanf("%d", &here);
		int *pos = lower_bound(arr + 1, arr + length + 1, here);
		*pos = here;
		if (pos == arr + length + 1)
			length++;
	}
	printf("%d\n", length);

	return 0;
}