#include<cstdio>
#include<algorithm>
using namespace std;

int arr[2000001];

int main() {
	int asize, bsize;
	scanf("%d %d", &asize, &bsize);
	for (int i = 0; i < asize; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = asize; i < asize + bsize; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + asize + bsize);

	for (int i = 0; i < asize + bsize; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}