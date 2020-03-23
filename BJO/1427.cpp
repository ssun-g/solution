#include<cstdio>
#include<algorithm>
using namespace std;

int arr[10];

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	int idx = 0;
	scanf("%d", &n);
	while (n) {
		arr[idx++] = n % 10;
		n /= 10;
	}

	sort(arr, arr + idx, comp);

	for (int i = 0; i < idx; i++) printf("%d", arr[i]);

	return 0;
}