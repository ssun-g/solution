#include<cstdio>
using namespace std;

int arr[10];

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("%d\n", n - sum);

	return 0;
}