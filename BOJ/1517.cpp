#include<cstdio>
using namespace std;

int arr[500001];
int tmp[500001];

long long merge(int start, int mid, int end) {
	int idx = start;
	int left = start;
	int right = mid + 1;

	long long cnt = 0;
	while (left <= mid && right <= end) {
		if (arr[left] <= arr[right]) tmp[idx++] = arr[left++];
		else {
			tmp[idx++] = arr[right++];
			cnt += (mid + 1 - left);
		}
	}

	while (left <= mid) tmp[idx++] = arr[left++];
	while (right <= end) tmp[idx++] = arr[right++];
	for (int i = start; i <= end; i++) arr[i] = tmp[i];

	return cnt;
}

long long merge_sort(int start, int end) {
	if (start == end) return 0;

	int mid = (start + end) / 2;
	long long result = merge_sort(start, mid) + merge_sort(mid + 1, end) + merge(start, mid, end);

	return result;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%lld\n", merge_sort(0, N - 1));

	return 0;
}