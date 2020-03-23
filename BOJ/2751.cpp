#include<cstdio>
#define MAX 1000000
using namespace std;

int arr[MAX], temp[MAX], n;
void go(int[], int, int);
void merge(int[], int, int, int);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	go(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

void go(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		go(arr, left, mid);
		go(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void merge(int arr[], int left, int mid, int right) {
	int nleft = left;
	int nright = right;
	int nmid = mid + 1;
	int index = left;
	while (nleft <= mid && nmid <= nright) {
		if (arr[nleft] <= arr[nmid])
			temp[index++] = arr[nleft++];
		else
			temp[index++] = arr[nmid++];
	}
	while (nleft <= mid)
		temp[index++] = arr[nleft++];
	while (nmid <= nright)
		temp[index++] = arr[nmid++];
	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
}