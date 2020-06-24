#include<cstdio>
using namespace std;

int main() {
	int n, result = 0;
	int arr[200001] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		result ^= arr[i];
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", result^arr[i]);
	}

	return 0;
}
