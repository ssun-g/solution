#include<cstdio>
#include<algorithm>
#define MAX 5000000
using namespace std;

int arr[MAX];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%d\n", arr[k - 1]);

	return 0;
}