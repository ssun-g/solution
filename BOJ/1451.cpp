#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

int rect[100][100];

long long sum(int sx, int sy, int ex, int ey) {
	long long ret = 0;
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			ret += rect[i][j];
		}
	}

	return ret;
}

int main() {
	int N, M;
	long long answer = LLONG_MIN;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &rect[i][j]);
		}
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			long long rect1 = sum(0, 0, M - 1, i);
			long long rect2 = sum(0, i + 1, M - 1, j);
			long long rect3 = sum(0, j + 1, M - 1, N - 1);

			answer = max(answer, rect1*rect2*rect3);
		}
	}

	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			long long rect1 = sum(0, 0, i, N - 1);
			long long rect2 = sum(i + 1, 0, j, N - 1);
			long long rect3 = sum(j + 1, 0, M - 1, N - 1);

			answer = max(answer, rect1*rect2*rect3);
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			long long rect1 = sum(0, 0, M - 1, i);
			long long rect2 = sum(0, i + 1, j, N - 1);
			long long rect3 = sum(j + 1, i + 1, M - 1, N - 1);

			answer = max(answer, rect1*rect2*rect3);
		}
	}

	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			long long rect1 = sum(0, 0, i, N - 1);
			long long rect2 = sum(i + 1, 0, M - 1, j);
			long long rect3 = sum(i + 1, j + 1, M - 1, N - 1);

			answer = max(answer, rect1*rect2*rect3);
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < M - 1; j++) {
			long long rect1 = sum(0, i, M - 1, N - 1);;
			long long rect2 = sum(0, 0, j, i - 1);
			long long rect3 = sum(j + 1, 0, M - 1, i - 1);

			answer = max(answer, rect1*rect2*rect3);
		}
	}

	for (int i = M - 1; i >= 1; i--) {
		for (int j = 0; j < N - 1; j++) {
			long long rect1 = sum(i, 0, M - 1, N - 1);
			long long rect2 = sum(0, 0, i - 1, j);
			long long rect3 = sum(0, j + 1, i - 1, N - 1);

			answer = max(answer, rect1*rect2*rect3);
		}
	}
	printf("%lld\n", answer);

	return 0;
}