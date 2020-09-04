#include<cstdio>
using namespace std;

int arr[1000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int cur = arr[i];
		int sum = 0;
		for (int i = 1; i < cur; i++) {
			if (cur%i == 0) sum += i;
		}
		if (sum == cur) printf("Perfect\n");
		else if (sum < cur) printf("Deficient\n");
		else printf("Abundant\n");
	}

	return 0;
}