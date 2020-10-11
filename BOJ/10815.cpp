#include<cstdio>
#include<algorithm>
using namespace std;

int card[500001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}
	sort(card, card + N);

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int c;
		scanf("%d", &c);

		int left = 0;
		int right = N - 1;
		int mid;
		bool flag = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (card[mid] < c) left = mid + 1;
			else if (card[mid] > c) right = mid - 1;
			else {
				flag = true;
				break;
			}
		}
		if (flag) printf("1 ");
		else printf("0 ");
	}

	return 0;
}