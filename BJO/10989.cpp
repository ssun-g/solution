#include<cstdio>
using namespace std;

int arr[10000];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		arr[n - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		while (arr[i]--) printf("%d\n", i + 1);
	}

	return 0;
}