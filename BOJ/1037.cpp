#include<cstdio>
#include<algorithm>
using namespace std;

int arr[50];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	printf("%d\n", arr[0] * arr[n - 1]);

	return 0;
}