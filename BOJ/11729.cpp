#include<cstdio>
#include<cmath>
using namespace std;

void hanoi(int from, int to, int by, int n) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(from, by, to, n - 1);
	printf("%d %d\n", from, to);
	hanoi(by, to, from, n - 1);
}

int main() {
	int N;
	scanf("%d", &N);

	int num = pow(2, N) - 1;
	printf("%d\n", num);
	hanoi(1, 3, 2, N);

	return 0;
}