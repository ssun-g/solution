#include<cstdio>
#include<math.h>
using namespace std;

int chess[15];
int n, result;

bool comp(int num) {
	for (int i = 0; i < num; i++) {
		if (chess[num] == chess[i] || abs(chess[num] - chess[i]) == (num - i)) return false;
	}
	return true;
}

void n_Queen(int num) {
	if (num == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		chess[num] = i;
		if (comp(num)) n_Queen(num + 1);
	}
}

int main() {
	scanf("%d", &n);
	n_Queen(0);
	printf("%d\n", result);

	return 0;
}