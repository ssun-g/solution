#include<cstdio>
#define MAX 100000
using namespace std;

int arr[MAX];

int main() {
	int n;
	scanf("%d", &n);
	arr[0] = 3;
	arr[1] = 7;
	for (int i = 2; i < n; i++) {
		arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
	}

	printf("%d\n", arr[n - 1]);

	return 0;
}