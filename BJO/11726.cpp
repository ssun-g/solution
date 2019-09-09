#include<cstdio>
using namespace std;

int arr[1001];

int main() {
	int n;
	scanf("%d", &n);
	arr[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	printf("%d\n", arr[n + 1]);

	return 0;
}