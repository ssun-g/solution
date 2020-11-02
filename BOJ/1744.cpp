#include<cstdio>
#include<algorithm>
using namespace std;

int arr[10001];

int main() {
	int N;
	int cnt = 0, answer = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);

	int tmp = 1;
	for (int i = 0; arr[i] <= 0; i++) {
		tmp *= arr[i];
		cnt++;
		if (cnt % 2 == 0 || arr[i + 1] > 0) {
			answer += tmp;
			tmp = 1;
		}
	}

	tmp = 1;
	cnt = 0;
	int comp = 0;
	for (int i = N - 1; arr[i] > 0; i--) {
		comp += arr[i];
		tmp *= arr[i];
		cnt++;
		if (cnt % 2 == 0 || arr[i - 1] <= 0) {
			if (comp <= tmp) answer += tmp;
			else answer += comp;
			comp = 0;
			tmp = 1;
		}
	}
	if (N == 1) printf("%d\n", arr[0]);
	else printf("%d\n", answer);

	return 0;
}