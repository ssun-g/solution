#include<cstdio>
#include<algorithm>
using namespace std;

int arr[2][100000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
	}

	arr[1][0] = arr[0][0];
	int MAX = arr[0][0];
	for (int i = 1; i < n; i++) {
		arr[1][i] = max(arr[1][i - 1] + arr[0][i], arr[0][i]);
		MAX = max(MAX, arr[1][i]);
	}

	printf("%d\n", MAX);

	return 0;
}