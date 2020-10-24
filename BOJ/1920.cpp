#include<cstdio>
#include<algorithm>
using namespace std;

int num[100001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int search;
		scanf("%d", &search);

		int left = 0;
		int right = N - 1;
		int mid;
		bool isHave = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] < search) left = mid + 1;
			else if (num[mid] > search) right = mid - 1;
			else {
				isHave = true;
				break;
			}
		}
		if (isHave) printf("1\n");
		else printf("0\n");
	}

	return 0;
}