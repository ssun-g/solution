#include<cstdio>
using namespace std;

int main() {
	int n, cnt = 1, num = 1, temp = 1;
	scanf("%d", &n);

	while (num < n) {
		temp = 6 * (cnt++);
		num += temp;
	}
	printf("%d\n", cnt);

	return 0;
}